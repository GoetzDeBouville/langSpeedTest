<?php
$start_time = microtime(true);

function arrayBuild($num) {
    $arr = [];
    for ($i = 0; $i < $num; $i++) {
        array_push($arr, rand(0, 1000));
    }
    return $arr;
}

function rearangeArr(&$array, $start) {
    for ($i = $start; $i < count($array); $i++) {
        [$array[$start], $array[$i]] = [$array[$i], $array[$start]];
        rearangeArr($array, $start + 1);
        [$array[$i], $array[$start]] = [$array[$start], $array[$i]];
    }
}

$array = arrayBuild(11);
rearangeArr($array, 0);

$end_time = microtime(true);
$execution_time = ($end_time - $start_time);

echo $execution_time . " sec\n";
?>
