/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2010                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Athanassios Boulis, Dimosthenis Pediaditakis                 *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *  
 ****************************************************************************/

#include "chaos.h"

Define_Module(chaos);

void chaos::startup()
{
	sampleInterval = (double)par("sampleInterval") / 1000;
	aggregatedValue = 0.0;
	waitingTimeForLowerLevelData = 0.0;
	lastSensedValue = 0.0;
	totalPackets = 0;
	//num_nodes = par("num_nodes");
	num_nodes = 16;
	node_id = atoi(SELF_NETWORK_ADDRESS);

	my_data.flag.set(node_id);
	my_data.val = node_id;
	my_data.node_id = node_id;

	trace() << "Node Startup " << node_id;

	is_pkt_recved = 0;

	complete_count = 0;
	sleep_count = 0;
	done = 0;

	num_rounds = 0;

	setTimer(SEND_AGGREGATED_VALUE, sampleInterval);

	if(node_id == 0) 
	{
		ChaosPacket *packet2Net = new ChaosPacket("chaos-pkt", APPLICATION_PACKET);
		packet2Net->setExtraData(my_data);
		packet2Net->setData(node_id);
		packet2Net->setSequenceNumber(totalPackets);
		toNetworkLayer(packet2Net, BROADCAST_NETWORK_ADDRESS);
		totalPackets++;
	}
}

void chaos::should_transmit()
{
	/*
		is new info received
			Yes -- Merge, mark new_recv_flag
			No  -- Do nothing
		is completed?
			Yes -- is complete_count < threshold
				Yes -- Transmit
				No  -- Report Done
			No  -- is new_recv_flag set?
				Yes -- Transmit
				No  -- is sleep timeout?
					Yes -- Randomly decide to Transmit
					No  -- sleep ++
	*/
	int new_recved = 0;

	will_transmit = 0;

	if(is_pkt_recved && ((my_data.flag | new_data.flag) != my_data.flag))
	{
		my_data.flag |= new_data.flag;
		my_data.val = max(my_data.val, new_data.val);
		new_recved = 1;
	}
	if(my_data.flag.count() == num_nodes)
	{
		complete_count += 1;
		if(complete_count < 5)
			will_transmit = 1;
		else
			done = 1;
	}
	else
	{
		if(new_recved == 1)
			will_transmit = 1;
		else if(sleep_count > 5)
		{
			if(rand() % 100 / 100.0 * 5.0 < sleep_count - 5)
				will_transmit = 1;
		}
	}

	is_pkt_recved = 0;

	if(!done)
	{
		if(will_transmit)
			sleep_count = 0;
		else
			sleep_count++;
	}
	else
	{
		trace() << "Node Done " << node_id << "Rounds: " << num_rounds;
	}
}

void chaos::timerFiredCallback(int index)
{
	switch (index) {
		
		case SEND_AGGREGATED_VALUE:{
			if(!done)
			{
				num_rounds++;
				setTimer(SEND_AGGREGATED_VALUE, sampleInterval);
				should_transmit();
				if(will_transmit)
				{
					ChaosPacket *packet2Net = new ChaosPacket("chaos-pkt", APPLICATION_PACKET);
					packet2Net->setExtraData(my_data);
					packet2Net->setData(node_id);
					packet2Net->setSequenceNumber(totalPackets);
					toNetworkLayer(packet2Net, BROADCAST_NETWORK_ADDRESS);
					totalPackets++;
				}
			}
			break;
		}
	}
}

void chaos::fromNetworkLayer(ApplicationPacket * genericPacket,
		 const char *source, double rssi, double lqi)
{
	ChaosPacket *rcvPacket = check_and_cast<ChaosPacket*>(genericPacket);
	new_data = rcvPacket->getExtraData();
	is_pkt_recved = 1;
}

void chaos::handleSensorReading(SensorReadingMessage * rcvReading)
{
	string sensType(rcvReading->getSensorType());
	double sensValue = rcvReading->getSensedValue();
	lastSensedValue = sensValue;
}

void chaos::handleNeworkControlMessage(cMessage * msg)
{
/*
    switch(msg->getKind()) {
    
	case TREE_LEVEL_UPDATED: {
	    // this message notifies the application of routing state (level)
	    // for certain routing protocols.
	    Network_ControlMessage *levelMsg = check_and_cast<Network_ControlMessage *>(msg);
	    routingLevel = levelMsg->getLevel();

	    waitingTimeForLowerLevelData = sampleInterval/pow((double)2,routingLevel);
	    trace() << "Routing level " << routingLevel;
	
	    setTimer(SEND_AGGREGATED_VALUE,waitingTimeForLowerLevelData);
	    break;
	}

	case CONNECTED_TO_TREE: {
	    Network_ControlMessage *connectedMsg = check_and_cast<Network_ControlMessage *>(msg);

	    int treeLevel = connectedMsg->getLevel();
	    string parents;
	    parents.assign(connectedMsg->getParents());

	    trace() << "Tree level " << treeLevel;

	    routingLevel = treeLevel;

	    waitingTimeForLowerLevelData = sampleInterval/pow((double)2,routingLevel);
	    setTimer(SEND_AGGREGATED_VALUE,waitingTimeForLowerLevelData);
	    break;
	}
    }
*/
}

