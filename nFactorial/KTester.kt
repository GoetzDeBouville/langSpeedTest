import kotlin.random.Random
import kotlin.time.ExperimentalTime
import kotlin.time.measureTime

@OptIn(ExperimentalTime::class)
fun main() {
    val array = arrayBuild(11).toIntArray()
    var time = measureTime {
        rearangeArr(array, 0)
    }
    println(time)
}

fun arrayBuild(num: Int): MutableList<Int> {

    val arr: MutableList<Int> = mutableListOf()
    (0 until num).forEach {
        arr.add(Random.nextInt(1000))
    }
    return arr
}

fun rearangeArr(array: IntArray, start: Int) {
    for (i in start until array.size) {
        array[start] = array[i].also { array[i] = array[start] }
        rearangeArr(array, start + 1)
        array[start] = array[i].also { array[i] = array[start] }
    }
}
