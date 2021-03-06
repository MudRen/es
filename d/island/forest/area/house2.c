#include "../tsunami.h"

inherit ROOM;
inherit DOORS;

void create()
{
    ::create();
    set_short("研究室");
    set_long(@LONG
一进到这间房子，只见到处都是实验用的仪器，虽然多，但却整理的有
条不紊；实验桌的後方排列著许多奇怪的大管子，里面有一些没见过的生物
，看来这儿是魔族研究生物兵器的场所。除了仪器外，桌上似乎还放了一些
颇吸引人的仪器，长得有点像水壶，用途倒是颇耐人寻味哦！
LONG
             );
    set("light",1);
    set("item_desc",([
        "canteen" : @LONG
这些水壶被很整齐放在一个离实验仪器有一段距离的地方，似乎是有
特别用途的，不知道可不可以跟主人要来看一看？
LONG
             ]) );
    set("exits",([
        "west":AREA"house1"]) );
    set("objects",([
        "flamen":TMOB"flamen"]) );
    create_door("west","east",([
         "keyword" :({"Oak door","door"}),
         "status"  :"closed",
         "name"    :"oak door",
         "c_name"  :"橡木门",
         "c_desc"  :"一道有著精致雕刻的橡木门"
               ]) );   
          reset();
}

