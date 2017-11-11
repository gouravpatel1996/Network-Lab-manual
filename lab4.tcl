
set ns [new Simulator]
set tf [open lab4.tr w]
$ns trace-all $tf
set nf [open lab4.nam w]
$ns namtrace-all $nf

$ns color 1 "red"
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]

$n1 label "Source/UDP"
$n3 label "Error Node"
$n5 label "Destination"

$ns make-lan "$n0 $n1 $n2 $n3" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns make-lan "$n4 $n5 $n6" 10Mb 10ms LL Queue/DropTail Mac/802_3
$ns duplex-link $n3 $n6 100Mb 10ms DropTail 
	
set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
set null5 [new Agent/Null]
$ns attach-agent $n5 $null5
$ns connect $udp1 $null5





$ns connect $udp1 $null5
$cbr1 set packetSize_ 1000
$cbr1 set interval_ 0.0001
$udp1 set class_ 1

set err [new ErrorModel]
$ns lossmodel $err $n3 $n6
$err set rate_ 0.2

proc finish { } {
global nf ns tf exec
exec nam lab4.nam &
close $tf
close $nf`
exit 0
}
$ns at 5.0 "finish"
$ns at 0.1 "$cbr1 start"
$ns run 																																																																																																																																																																													
