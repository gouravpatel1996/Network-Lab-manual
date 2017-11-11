set ns [new Simulator]
set tf [open lab5.tr w]
$ns trace-all $tf
set nf [open lab5.nam w]
$ns namtrace-all $nf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns color 1 "red"
$ns color 2 "green"

$ns make-lan "$n0 $n1 $n2 $n3" 10mb 10ms LL Queue/DropTail Mac/802_3

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
set sink3 [new Agent/TCPSink]
$ns attach-agent $n3 $sink3

$tcp0 set class_ 1

$ns connect $tcp0 $sink3
set tcp2 [new Agent/TCP]
$ns attach-agent $n2 $tcp2
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
set sink2 [new Agent/TCPSink]
$ns attach-agent $n1 $sink2

$tcp2 set class_ 2

$ns connect $tcp2 $sink2
set file1 [open file1.tr w]
$tcp0 attach $file1
$tcp0 trace cwnd_
$tcp0 set maxcwnd_ 10

set file2 [open file2.tr w]
$tcp2 attach $file2
$tcp2 trace cwnd_

proc finish { } {
global nf tf ns
$ns flush-trace
exec nam lab5.nam &
close $nf
close $tf
exit 0
}

$ns at 0.1 "$ftp0 start"
$ns at 0.5 "$ftp0 stop"

$ns at 2 "$ftp0 start"
$ns at 3 "$ftp0 stop"

$ns at 0.2 "$ftp2 start"
$ns at 2 "$ftp2 stop"

$ns at 2.5 "$ftp2 start"
$ns at 4 "$ftp2 stop"

$ns at 5.0 "finish"
$ns run