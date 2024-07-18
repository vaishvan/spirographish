# spirographish
Spirograph animation with command line inputs and animations, written in C++ and with the help of the SFML graphics library.<br>

/---------------------INPUTS-------------------------/<br>
r: distance b/w the center of the smaller circle and the point from which we draw the graph.<br>

d: diameter of the smaller circle.<br>

R: distance b/w center of the bigger and smaller circle.<br>

cx: x-coordinate of the center of the bigger circle.<br>

cy: y-coordinate of the center of the bigger circle.<br>

red, blue, green: RGB color values.<br>

sign: defines orientation. in natural cases, sign is negative, ie the circles move opposite wrt each other. negative is denoted by "m"(without the double quotes).<br>

width: width of the line drawn.<br>

number of points: determines how smooth the curves will be. it is the number of line segments to be joined for a single curve at a time. the higher the number, the smoother the graph.<br>


e: Represents the eccentricity, which is the ratio of the distance between the center of the rolling circle and the drawing pen (d) to the radius of the rolling circle (r).<br>

k: ratio of the radius of the rolling circle (r) to the radius of the fixed circle (R).<br>

NB: e and k have been included just for future reference to the code. they are not inputs!!!<br>

/-------------ADDITIONAL RESOURCES---------------/<br>
https://www.mathematische-basteleien.de/spirographs.htm#:~:text=The%20general%20parametric%20representation%20is,point%20P%20of%20its%20center.&text=There%20are%20r%3D3%20and,a%3D5%20(red).<br>

https://scholarship.claremont.edu/cgi/viewcontent.cgi?article=1328&context=hmnj<br>

/-----------------INPUT EXAMPLES -------------------------/ <br>
79. 190. 200. 960 540 100 255 0 m 1 10 <br>
79. 190. 200. 960 540 100 0 0 m 1 10 <br>
