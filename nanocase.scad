difference(){
    translate([-2,-2.5,0]){
    cube([50,25,6.3]);
    }
    for (i = [0:15]){
translate([2+i*2.54,1,0.3]){    
    #cube([1,1,7]);
    
}
}
for (i = [0:15]){
translate([2+i*2.54,16+2,0.3]){    
    #cube([1,1,7]);
}
}
    
}

difference(){
    translate([-2,-2.5,0]){
    cube([50,25,15]);
    } 
    translate([-2.5,-0.5,5]){
    cube([50-2,21,11]);
    }
}
