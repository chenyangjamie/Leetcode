# Leetcode

https://leetcode.com/discuss/52999/fully-explained-why-fast-and-slow-can-meet-in-the-cycle

讲得非常好，系统介绍了这个判断链表中是否有环的方法（无额外空间需求）

更进一步的，可以推断出当fast==slow时，从这个meet点到circle的entry的距离 == 从head到circle的entry的距离，即可解决此题。