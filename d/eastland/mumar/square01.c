#include <mumar.h>
inherit ROOM;
int cockroach = 1;
int fragment = 1;
 
void create()
{
        ::create();
  set_short("牧马关教场");
  set_long( @CLong
这儿是教场的西南角落，由於长满了青苔，使得城墙看起来像是上了绿漆一般，
你彷佛听见一阵阵的脚步声和谈话声从城墙上传来。墙角整齐地堆积著一些杂物和箱
子(box) ，地面上则还有一些燃烧过的痕迹。
CLong
);
  set( "c_item_desc", ([
                "box" : @LONG_TEXT
这些箱子上都写著「军用品」、「小心轻放」之类的字眼，不过不知道放在这儿
多久了，经过风吹雨打日晒，有些已经腐朽变形了。
LONG_TEXT
 ]) );
set_outside("eastland");
set("exits",([
               "north": MUMAR "square04",
               "east": MUMAR "square02" ]));
set( "search_desc", ([ "box" : "@@search_box","corner": "@@search_corner" ]) );
        reset();
}
 
string search_box()
{
        object obj;
 
        if( !cockroach || present("cockroach", this_object()) ) return
        "你把所有的箱子都翻了一遍，但是什麽都找不到。\n";
        obj = new( MOB"cockroach" );
        obj->move( this_object() );
        cockroach = 0;
        return
        "你开始翻箱倒柜地找东西，忽然跑出了一个黑色毛茸茸的东西...吓！蟑螂！\n";
}
 
string search_corner()
{
        object obj;
 
        if( !fragment || present("fragment", this_object()) ) return
          "你在角落里找了半天，但是连个石头都没有看到。\n";
        obj = new( OBJS"fragment" );
        obj->move( this_object() );
        fragment = 0;
        return
         "你在角落里开始翻箱倒柜地找东西，终於找到了一片碎镜子！\n";
}
