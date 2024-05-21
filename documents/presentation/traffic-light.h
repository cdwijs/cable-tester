//https://edotor.net/

digraph
{
    #node [shape=record, color=red];
    #edge [arrowhead=open,color=green];

    #rankdir="TD"
    
    ST_GREEN [label = "green"];
    ST_ORANGE [label = "orange"];
    ST_RED [label = "red"];


    ST_GREEN -> ST_ORANGE [label = " timer elapsed"];

    ST_ORANGE -> ST_RED [label = " timer elapsed"];

    ST_RED -> ST_GREEN [label = " timer elapsed"];
}