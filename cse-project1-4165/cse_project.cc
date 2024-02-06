/*

Prajwal Gowda Rampura Suresh

1002064165

pxr4165@mavs.uta.edu

Computer Networks

*/



// including necessary header files.



#include "ns3/core-module.h"

#include "ns3/network-module.h"

#include "ns3/internet-module.h"

#include "ns3/point-to-point-module.h"

#include "ns3/applications-module.h"

#include "ns3/netanim-module.h"

#include "ns3/mobility-module.h"

#include "ns3/flow-monitor-module.h"

using namespace ns3;



NS_LOG_COMPONENT_DEFINE ("FirstScriptExample");



Ptr<FlowMonitor> monitor;

FlowMonitorHelper flowmon;



// code to calculate goodput and throughput



void averageThroughput()

{



        Ptr<Ipv4FlowClassifier> classifier = DynamicCast<Ipv4FlowClassifier> (flowmon.GetClassifier ());

        std::map<FlowId, FlowMonitor::FlowStats> stats = monitor->GetFlowStats ();

        for (std::map<FlowId, FlowMonitor::FlowStats>::const_iterator i = stats.begin (); i != stats.end (); ++i)

        {

                Ipv4FlowClassifier::FiveTuple t = classifier->FindFlow (i->first);

                std::cout << "Flow " << i->first  << " (" << t.sourceAddress << " -> " << t.destinationAddress << ")\n";

                std::cout << "  Tx Packets: " << i->second.txPackets << "\n";

                std::cout << "  Tx Bytes:   " << i->second.txBytes << "\n";

                std::cout << "  Throughput:  " << i->second.txBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds()) / 1024 / 1024  << " Mbps\n";

                std::cout << "  Rx Packets: " << i->second.rxPackets << "\n";

                std::cout << "  Rx Bytes:   " << i->second.rxBytes << "\n";

                std::cout << "  Goodput: " << i->second.rxBytes * 8.0 / (i->second.timeLastRxPacket.GetSeconds() - i->second.timeFirstTxPacket.GetSeconds()) / 1024 / 1024  << " Mbps\n";

        }



}



int

main (int argc, char *argv[])

{

        //generate nodes

        

        NodeContainer nodes;

        nodes.Create (30);



        //connect nodes e2 and s6

        

        NodeContainer e2s6;

        e2s6.Add(nodes.Get(0));

        e2s6.Add(nodes.Get(1));	

        

        //connect nodes e2 and s2



        NodeContainer e2s2;

        e2s2.Add(nodes.Get(0));

        e2s2.Add(nodes.Get(2));	

        

        //connect nodes e2 and s1

        

        NodeContainer e2s1;

        e2s1.Add(nodes.Get(0));

        e2s1.Add(nodes.Get(3));	

        

        //connect nodes e2 and d7

        

        NodeContainer e2d7;

        e2d7.Add(nodes.Get(0));

        e2d7.Add(nodes.Get(4));	

        

        //connect nodes e2 and b2

        

        NodeContainer e2b2;

        e2b2.Add(nodes.Get(0));

        e2b2.Add(nodes.Get(5));	

        

        //connect nodes b2 and b1

        

        NodeContainer b2b1;

        b2b1.Add(nodes.Get(5));

        b2b1.Add(nodes.Get(6));	

        

        //connect nodes e1 and b1

        

        NodeContainer e1b1;

        e1b1.Add(nodes.Get(7));

        e1b1.Add(nodes.Get(6)); 

        

        //connect nodes e1 and s7

        

        NodeContainer e1s7;

        e1s7.Add(nodes.Get(7));

        e1s7.Add(nodes.Get(8));	

        

        //connect nodes e1 and s4

        

        NodeContainer e1s4;

        e1s4.Add(nodes.Get(7));

        e1s4.Add(nodes.Get(9));	

        

        //connect nodes e1 and s3

        

        NodeContainer e1s3;

        e1s3.Add(nodes.Get(7));

        e1s3.Add(nodes.Get(10)); 

        

        //connect nodes b1 and b7

        

        NodeContainer b1b7;

        b1b7.Add(nodes.Get(6));

        b1b7.Add(nodes.Get(11)); 

        

        //connect nodes b7 and b6

        

        NodeContainer b7b6;

        b7b6.Add(nodes.Get(11));

        b7b6.Add(nodes.Get(12)); 

        

        //connect nodes e6 and b6

        

        NodeContainer e6b6;

        e6b6.Add(nodes.Get(13));

        e6b6.Add(nodes.Get(12)); 

        

        //connect nodes e6 and d5

        

        NodeContainer e6d5;

        e6d5.Add(nodes.Get(13));

        e6d5.Add(nodes.Get(14)); 

        

        //connect nodes e6 and d6

        

        NodeContainer e6d6;

        e6d6.Add(nodes.Get(13));

        e6d6.Add(nodes.Get(15)); 

        

        //connect nodes b7 and b8

        

        NodeContainer b7b8;

        b7b8.Add(nodes.Get(11));

        b7b8.Add(nodes.Get(16)); 

        

        //connect nodes b2 and b7

        

        NodeContainer b2b7;

        b2b7.Add(nodes.Get(5));

        b2b7.Add(nodes.Get(11)); 

        

        //connect nodes b2 and b8

        

        NodeContainer b2b8;

        b2b8.Add(nodes.Get(5));

        b2b8.Add(nodes.Get(16)); 

        

        //connect nodes b8 and b3

        

        NodeContainer b8b3;

        b8b3.Add(nodes.Get(16));

        b8b3.Add(nodes.Get(17)); 

        

        //connect nodes e3 and b3

        

        NodeContainer e3b3;

        e3b3.Add(nodes.Get(18));

        e3b3.Add(nodes.Get(17)); 

        

        //connect nodes e3 and s5

        

        NodeContainer e3s5;

        e3s5.Add(nodes.Get(18));

        e3s5.Add(nodes.Get(19)); 

        

        //connect nodes e3 and s8

        

        NodeContainer e3s8;

        e3s8.Add(nodes.Get(18));

        e3s8.Add(nodes.Get(20)); 

        

        //connect nodes b3 and b4

        

        NodeContainer b3b4;

        b3b4.Add(nodes.Get(17));

        b3b4.Add(nodes.Get(21)); 

        

        //connect nodes b8 and b4

        

        NodeContainer b8b4;

        b8b4.Add(nodes.Get(16));

        b8b4.Add(nodes.Get(21)); 

        

        //connect nodes e4 and b4

        

        NodeContainer e4b4;

        e4b4.Add(nodes.Get(22));

        e4b4.Add(nodes.Get(21)); 

        

        //connect nodes e4 and d8

        

        NodeContainer e4d8;

        e4d8.Add(nodes.Get(22));

        e4d8.Add(nodes.Get(23)); 

        

        //connect nodes e4 and d3

        

        NodeContainer e4d3;

        e4d3.Add(nodes.Get(22));

        e4d3.Add(nodes.Get(24)); 

        

        //connect nodes e4 and d1

        

        NodeContainer e4d1;

        e4d1.Add(nodes.Get(22));

        e4d1.Add(nodes.Get(25)); 

        

        //connect nodes b8 and b5

        

        NodeContainer b8b5;

        b8b5.Add(nodes.Get(16));

        b8b5.Add(nodes.Get(26)); 

        

        //connect nodes b7 and b5

        

        NodeContainer b7b5;

        b7b5.Add(nodes.Get(11));

        b7b5.Add(nodes.Get(26)); 

        

        //connect nodes e5 and b5

        

        NodeContainer e5b5;

        e5b5.Add(nodes.Get(27));

        e5b5.Add(nodes.Get(26)); 

        

        //connect nodes e5 and d2

        

        NodeContainer e5d2;

        e5d2.Add(nodes.Get(27));

        e5d2.Add(nodes.Get(28)); 

        

        //connect nodese5 and d4

        

        NodeContainer e5d4;

        e5d4.Add(nodes.Get(27));

        e5d4.Add(nodes.Get(29)); 



        //Link Capacity Setting 



        PointToPointHelper pointToPointe2s6;

        PointToPointHelper pointToPointe2s2;

        PointToPointHelper pointToPointe2s1;

        PointToPointHelper pointToPointe2d7;

        PointToPointHelper pointToPointe2b2;

        PointToPointHelper pointToPointb2b1;

        PointToPointHelper pointToPointe1b1;

        PointToPointHelper pointToPointe1s7;

        PointToPointHelper pointToPointe1s4;

        PointToPointHelper pointToPointe1s3;

        PointToPointHelper pointToPointb1b7;

        PointToPointHelper pointToPointb7b6;

        PointToPointHelper pointToPointe6b6;

        PointToPointHelper pointToPointe6d5;

        PointToPointHelper pointToPointe6d6;

        PointToPointHelper pointToPointb7b8;

        PointToPointHelper pointToPointb2b7;

        PointToPointHelper pointToPointb2b8;

        PointToPointHelper pointToPointb8b3;

        PointToPointHelper pointToPointe3b3;

        PointToPointHelper pointToPointe3s5;

        PointToPointHelper pointToPointe3s8;

        PointToPointHelper pointToPointb3b4;

        PointToPointHelper pointToPointb8b4;

        PointToPointHelper pointToPointe4b4;

        PointToPointHelper pointToPointe4d8;

        PointToPointHelper pointToPointe4d3;

        PointToPointHelper pointToPointe4d1;

        PointToPointHelper pointToPointb8b5;

        PointToPointHelper pointToPointb7b5;

        PointToPointHelper pointToPointe5b5;

        PointToPointHelper pointToPointe5d2;

        PointToPointHelper pointToPointe5d4;

        

        

        pointToPointe2b2.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe2b2.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointe1b1.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe1b1.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointe6b6.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe6b6.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointe3b3.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe3b3.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointe4b4.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe4b4.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointe5b5.SetDeviceAttribute ("DataRate", StringValue ("10Mbps"));

        pointToPointe5b5.SetChannelAttribute ("Delay", StringValue ("2ms"));

        

        pointToPointb8b5.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb8b5.SetChannelAttribute ("Delay", StringValue ("9.2ms"));

        

        pointToPointb7b5.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb7b5.SetChannelAttribute ("Delay", StringValue ("8.2ms"));

        

        pointToPointb3b4.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb3b4.SetChannelAttribute ("Delay", StringValue ("23ms"));

        

        pointToPointb8b4.SetDeviceAttribute ("DataRate", StringValue ("3Mbps"));

        pointToPointb8b4.SetChannelAttribute ("Delay", StringValue ("1.5ms"));

        

        pointToPointb7b8.SetDeviceAttribute ("DataRate", StringValue ("2.5Mbps"));

        pointToPointb7b8.SetChannelAttribute ("Delay", StringValue ("3.4ms"));

        

        pointToPointb2b7.SetDeviceAttribute ("DataRate", StringValue ("1.2Mbps"));

        pointToPointb2b7.SetChannelAttribute ("Delay", StringValue ("6.5ms"));

        

        pointToPointb2b8.SetDeviceAttribute ("DataRate", StringValue ("2.8Mbps"));

        pointToPointb2b8.SetChannelAttribute ("Delay", StringValue ("2.3ms"));

        

        pointToPointb8b3.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb8b3.SetChannelAttribute ("Delay", StringValue ("2.5ms"));

        

        pointToPointb2b1.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb2b1.SetChannelAttribute ("Delay", StringValue ("10ms"));

        

        pointToPointb1b7.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb1b7.SetChannelAttribute ("Delay", StringValue ("7.2ms"));

        

        pointToPointb7b6.SetDeviceAttribute ("DataRate", StringValue ("1.5Mbps"));

        pointToPointb7b6.SetChannelAttribute ("Delay", StringValue ("13.1ms"));



        NetDeviceContainer de2s6 = pointToPointe2s6.Install(e2s6);

        NetDeviceContainer de2s2 = pointToPointe2s2.Install(e2s2);

        NetDeviceContainer de2s1 = pointToPointe2s1.Install(e2s1);

        NetDeviceContainer de2d7 = pointToPointe2d7.Install(e2d7);

        NetDeviceContainer de2b2 = pointToPointe2b2.Install(e2b2);

        NetDeviceContainer db2b1 = pointToPointb2b1.Install(b2b1);

        NetDeviceContainer de1b1 = pointToPointe1b1.Install(e1b1);

        NetDeviceContainer de1s7 = pointToPointe1s7.Install(e1s7);

        NetDeviceContainer de1s4 = pointToPointe1s4.Install(e1s4);

        NetDeviceContainer de1s3 = pointToPointe1s3.Install(e1s3);

        NetDeviceContainer db1b7 = pointToPointb1b7.Install(b1b7);

        NetDeviceContainer db7b6 = pointToPointb7b6.Install(b7b6);

        NetDeviceContainer de6b6 = pointToPointe6b6.Install(e6b6);

        NetDeviceContainer de6d5 = pointToPointe6d5.Install(e6d5);

        NetDeviceContainer de6d6 = pointToPointe6d6.Install(e6d6);

        NetDeviceContainer db7b8 = pointToPointb7b8.Install(b7b8);

        NetDeviceContainer db2b7 = pointToPointb2b7.Install(b2b7);

        NetDeviceContainer db2b8 = pointToPointb2b8.Install(b2b8);

        NetDeviceContainer db8b3 = pointToPointb8b3.Install(b8b3);

        NetDeviceContainer de3b3 = pointToPointe3b3.Install(e3b3);

        NetDeviceContainer de3s5 = pointToPointe3s5.Install(e3s5);

        NetDeviceContainer de3s8 = pointToPointe3s8.Install(e3s8);

        NetDeviceContainer db3b4 = pointToPointb3b4.Install(b3b4);

        NetDeviceContainer db8b4 = pointToPointb8b4.Install(b8b4);

        NetDeviceContainer de4b4 = pointToPointe4b4.Install(e4b4);

        NetDeviceContainer de4d8 = pointToPointe4d8.Install(e4d8);

        NetDeviceContainer de4d3 = pointToPointe4d3.Install(e4d3);

        NetDeviceContainer de4d1 = pointToPointe4d1.Install(e4d1);

        NetDeviceContainer db8b5 = pointToPointb8b5.Install(b8b5);

        NetDeviceContainer db7b5 = pointToPointb7b5.Install(b7b5);

        NetDeviceContainer de5b5 = pointToPointe5b5.Install(e5b5);

        NetDeviceContainer de5d2 = pointToPointe5d2.Install(e5d2);

        NetDeviceContainer de5d4 = pointToPointe5d4.Install(e5d4);





        InternetStackHelper stack;

        stack.Install (nodes);



        //assigning  Ip address

        

        Ipv4AddressHelper address;

        Ipv4InterfaceContainer ie2s6;

        Ipv4InterfaceContainer ie2s2;

        Ipv4InterfaceContainer ie2s1;

        Ipv4InterfaceContainer ie2d7;

        Ipv4InterfaceContainer ie2b2;

        Ipv4InterfaceContainer ib2b1;

        Ipv4InterfaceContainer ie1b1;

        Ipv4InterfaceContainer ie1s7;

        Ipv4InterfaceContainer ie1s4;

        Ipv4InterfaceContainer ie1s3;

        Ipv4InterfaceContainer ib1b7;

        Ipv4InterfaceContainer ib7b6;

        Ipv4InterfaceContainer ie6b6;

        Ipv4InterfaceContainer ie6d5;

        Ipv4InterfaceContainer ie6d6;

        Ipv4InterfaceContainer ib7b8;

        Ipv4InterfaceContainer ib2b7;

        Ipv4InterfaceContainer ib2b8;

        Ipv4InterfaceContainer ib8b3;

        Ipv4InterfaceContainer ie3b3;

        Ipv4InterfaceContainer ie3s5;

        Ipv4InterfaceContainer ie3s8;

        Ipv4InterfaceContainer ib3b4;

        Ipv4InterfaceContainer ib8b4;

        Ipv4InterfaceContainer ie4b4;

        Ipv4InterfaceContainer ie4d8;

        Ipv4InterfaceContainer ie4d3;

        Ipv4InterfaceContainer ie4d1;

        Ipv4InterfaceContainer ib8b5;

        Ipv4InterfaceContainer ib7b5;

        Ipv4InterfaceContainer ie5b5;

        Ipv4InterfaceContainer ie5d2;

        Ipv4InterfaceContainer ie5d4;





        address.SetBase ("10.1.1.0", "255.255.255.0");

        ie2s6 = address.Assign(de2s6);



        address.SetBase ("10.1.2.0", "255.255.255.0");

        ie2s2 = address.Assign(de2s2);

        

        address.SetBase ("10.1.3.0", "255.255.255.0");

        ie2s1 = address.Assign(de2s1);

        

        address.SetBase ("10.1.4.0", "255.255.255.0");

        ie2d7 = address.Assign(de2d7);

        

        address.SetBase ("10.1.5.0", "255.255.255.0");

        ie2b2 = address.Assign(de2b2);

        

        address.SetBase ("10.1.6.0", "255.255.255.0");

        ib2b1 = address.Assign(db2b1);



        address.SetBase ("10.1.7.0", "255.255.255.0");

        ie1b1 = address.Assign(de1b1);

        

        address.SetBase ("10.1.8.0", "255.255.255.0");

        ie1s7 = address.Assign(de1s7);

        

        address.SetBase ("10.1.9.0", "255.255.255.0");

        ie1s4 = address.Assign(de1s4);

        

        address.SetBase ("10.1.10.0", "255.255.255.0");

        ie1s3 = address.Assign(de1s3);

        

        address.SetBase ("10.1.11.0", "255.255.255.0");

        ib1b7 = address.Assign(db1b7);



        address.SetBase ("10.1.12.0", "255.255.255.0");

        ib7b6 = address.Assign(db7b6);

        

        address.SetBase ("10.1.13.0", "255.255.255.0");

        ie6b6 = address.Assign(de6b6);

        

        address.SetBase ("10.1.14.0", "255.255.255.0");

        ie6d5 = address.Assign(de6d5);

        

        address.SetBase ("10.1.15.0", "255.255.255.0");

        ie6d6 = address.Assign(de6d6);

        

        address.SetBase ("10.1.16.0", "255.255.255.0");

        ib7b8 = address.Assign(db7b8);



        address.SetBase ("10.1.17.0", "255.255.255.0");

        ib2b7 = address.Assign(db2b7);

        

        address.SetBase ("10.1.18.0", "255.255.255.0");

        ib2b8 = address.Assign(db2b8);

        

        address.SetBase ("10.1.19.0", "255.255.255.0");

        ib8b3 = address.Assign(db8b3);

        

        address.SetBase ("10.1.20.0", "255.255.255.0");

        ie3b3 = address.Assign(de3b3);

        

        address.SetBase ("10.1.21.0", "255.255.255.0");

        ie3s5 = address.Assign(de3s5);

        

        address.SetBase ("10.1.22.0", "255.255.255.0");

        ie3s8 = address.Assign(de3s8);



        address.SetBase ("10.1.23.0", "255.255.255.0");

        ib3b4 = address.Assign(db3b4);

        

        address.SetBase ("10.1.24.0", "255.255.255.0");

        ib8b4 = address.Assign(db8b4);

        

        address.SetBase ("10.1.25.0", "255.255.255.0");

        ie4b4 = address.Assign(de4b4);

        

        address.SetBase ("10.1.26.0", "255.255.255.0");

        ie4d8 = address.Assign(de4d8);

        

        address.SetBase ("10.1.27.0", "255.255.255.0");

        ie4d3 = address.Assign(de4d3);



        address.SetBase ("10.1.28.0", "255.255.255.0");

        ie4d1 = address.Assign(de4d1);

        

        address.SetBase ("10.1.29.0", "255.255.255.0");

        ib8b5 = address.Assign(db8b5);

        

        address.SetBase ("10.1.30.0", "255.255.255.0");

        ib7b5 = address.Assign(db7b5);

        

        address.SetBase ("10.1.31.0", "255.255.255.0");

        ie5b5 = address.Assign(de5b5);

        

        address.SetBase ("10.1.32.0", "255.255.255.0");

        ie5d2 = address.Assign(de5d2);



        address.SetBase ("10.1.33.0", "255.255.255.0");

        ie5d4 = address.Assign(de5d4);







        //generating routing table 

        Ipv4GlobalRoutingHelper::PopulateRoutingTables ();



        uint16_t port = 9;

        

        //sink deploy d1

        PacketSinkHelper sink1("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps1 = sink1.Install(nodes.Get(25));



        sinkApps1.Start(Seconds(0.0));

        sinkApps1.Stop(Seconds(2.0));

        

        //sink deploy d2

        PacketSinkHelper sink2("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps2 = sink2.Install(nodes.Get(28));



        sinkApps2.Start(Seconds(0.0));

        sinkApps2.Stop(Seconds(2.0));

        

        //sink deploy d3

        PacketSinkHelper sink3("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps3 = sink3.Install(nodes.Get(24));



        sinkApps3.Start(Seconds(0.0));

        sinkApps3.Stop(Seconds(2.0));

        

        //sink deploy d4

        PacketSinkHelper sink4("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps4 = sink4.Install(nodes.Get(29));



        sinkApps4.Start(Seconds(0.0));

        sinkApps4.Stop(Seconds(2.0));

        

        //sink deploy d5

        PacketSinkHelper sink5("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps5 = sink5.Install(nodes.Get(14));



        sinkApps5.Start(Seconds(0.0));

        sinkApps5.Stop(Seconds(2.0));

        

        //sink deploy d6

        PacketSinkHelper sink6("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps6 = sink6.Install(nodes.Get(15));



        sinkApps6.Start(Seconds(0.0));

        sinkApps6.Stop(Seconds(2.0));

        

        //sink deploy d7

        PacketSinkHelper sink7("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps7 = sink7.Install(nodes.Get(4));



        sinkApps7.Start(Seconds(0.0));

        sinkApps7.Stop(Seconds(2.0));

        

        //sink deploy d8

        PacketSinkHelper sink8("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address::GetAny(), port));

        ApplicationContainer sinkApps8 = sink8.Install(nodes.Get(23));



        sinkApps8.Start(Seconds(0.0));

        sinkApps8.Stop(Seconds(2.0));







        //flow s1

        BulkSendHelper sources1("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie4d1.GetAddress(1)), port));

        sources1.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps1 = sources1.Install(nodes.Get(3));

        sourceApps1.Start(Seconds(0.0));

        sourceApps1.Stop(Seconds(2.0));

        

        //flow s2

        BulkSendHelper sources2("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie5d2.GetAddress(1)), port));

        sources2.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps2 = sources2.Install(nodes.Get(2));

        sourceApps2.Start(Seconds(0.0));

        sourceApps2.Stop(Seconds(2.0));

        

        //flow s3

        BulkSendHelper sources3("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie4d3.GetAddress(1)), port));

        sources3.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps3 = sources3.Install(nodes.Get(10));

        sourceApps3.Start(Seconds(0.0));

        sourceApps3.Stop(Seconds(2.0));

        

        //flow s4

        BulkSendHelper sources4("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie5d4.GetAddress(1)), port));

        sources4.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps4 = sources4.Install(nodes.Get(9));

        sourceApps4.Start(Seconds(0.0));

        sourceApps4.Stop(Seconds(2.0));

        

        //flow s5

        BulkSendHelper sources5("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie6d5.GetAddress(1)), port));

        sources5.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps5 = sources5.Install(nodes.Get(19));

        sourceApps5.Start(Seconds(0.0));

        sourceApps5.Stop(Seconds(2.0));

        

        //flow s6

        BulkSendHelper sources6("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie6d6.GetAddress(1)), port));

        sources6.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps6 = sources6.Install(nodes.Get(1));

        sourceApps6.Start(Seconds(0.0));

        sourceApps6.Stop(Seconds(2.0));

        

        //flow s7

        BulkSendHelper sources7("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie2d7.GetAddress(1)), port));

        sources7.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps7 = sources7.Install(nodes.Get(8));

        sourceApps7.Start(Seconds(0.0));

        sourceApps7.Stop(Seconds(2.0));

        

        //flow s8

        BulkSendHelper sources8("ns3::TcpSocketFactory", InetSocketAddress(Ipv4Address(ie4d8.GetAddress(1)), port));

        sources8.SetAttribute("MaxBytes", UintegerValue(0));

        ApplicationContainer sourceApps8 = sources8.Install(nodes.Get(20));

        sourceApps8.Start(Seconds(0.0));

        sourceApps8.Stop(Seconds(2.0));

        



        //animation generate

        MobilityHelper MH;

        MH.SetMobilityModel("ns3::ConstantPositionMobilityModel");

        MH.Install(nodes);



        AnimationInterface anim ("cse_proj.xml");                   // output .xml name

        

        //max packets number for one animation file

        anim.SetMaxPktsPerTraceFile(5000000);

        

        //Convert the node to animation type

        Ptr<ConstantPositionMobilityModel> e2 = nodes.Get(0)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s6 = nodes.Get(1)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s2 = nodes.Get(2)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s1 = nodes.Get(3)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d7 = nodes.Get(4)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b2 = nodes.Get(5)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b1 = nodes.Get(6)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> e1 = nodes.Get(7)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s7 = nodes.Get(8)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s4 = nodes.Get(9)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s3 = nodes.Get(10)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b7 = nodes.Get(11)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b6 = nodes.Get(12)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> e6 = nodes.Get(13)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d5 = nodes.Get(14)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d6 = nodes.Get(15)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b8 = nodes.Get(16)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b3 = nodes.Get(17)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> e3 = nodes.Get(18)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s5 = nodes.Get(19)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> s8 = nodes.Get(20)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b4 = nodes.Get(21)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> e4 = nodes.Get(22)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d8 = nodes.Get(23)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d3 = nodes.Get(24)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d1 = nodes.Get(25)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> b5 = nodes.Get(26)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> e5 = nodes.Get(27)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d2 = nodes.Get(28)->GetObject<ConstantPositionMobilityModel>();

        Ptr<ConstantPositionMobilityModel> d4 = nodes.Get(29)->GetObject<ConstantPositionMobilityModel>(); 

               

        //Set the position of each node

        e6->SetPosition(Vector(20,80,0));

        b6->SetPosition(Vector(40,80,0));

        b7->SetPosition(Vector(60,80,0));

        b8->SetPosition(Vector(80,80,0));

        b3->SetPosition(Vector(100,80,0));

        e3->SetPosition(Vector(120,80,0));

        

        d5->SetPosition(Vector(5,65,0));

        d6->SetPosition(Vector(5,95,0));

        s5->SetPosition(Vector(135,65,0));

        s8->SetPosition(Vector(135,95,0));

        

        b1->SetPosition(Vector(55,60,0));

        b2->SetPosition(Vector(85,60,0));

        b5->SetPosition(Vector(50,100,0));

        b4->SetPosition(Vector(90,100,0));

        

        e5->SetPosition(Vector(40,120,0));

        d2->SetPosition(Vector(30,122,0));

        d4->SetPosition(Vector(35,135,0));

        

        e4->SetPosition(Vector(100,120,0));

        d1->SetPosition(Vector(90,130,0));

        d3->SetPosition(Vector(105,135,0));

        d8->SetPosition(Vector(115,122,0));

        

        e1->SetPosition(Vector(40,40,0));

        s7->SetPosition(Vector(45,20,0));

        s4->SetPosition(Vector(35,17,0));

        s3->SetPosition(Vector(20,25,0));

        

        e2->SetPosition(Vector(100,40,0));

        s6->SetPosition(Vector(120,45,0));

        s2->SetPosition(Vector(117,30,0));

        s1->SetPosition(Vector(105,15,0));

        d7->SetPosition(Vector(95,20,0));

        

        

        Simulator::Schedule(Seconds(2.0), &averageThroughput);

	monitor = flowmon.InstallAll ();

	

  Simulator::Stop (Seconds (2));

  Simulator::Run ();

  Simulator::Destroy ();

  return 0;

}

