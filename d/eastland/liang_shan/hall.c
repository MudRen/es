#include <takeda.h>

inherit ROOM;

void create()
{
	object hu;
	::create();
	set_short( "������" );
	set_long(
	"���������������һ���ǳ����Ĵ�������������һ��Ƭ֯�����ʺ�\n"
	"��̺������һ����ů���ʵĸо�����������������һ���������̴���Ρ�\n"
	"��ɽ��һ��������ú��������ڴ����ִ�ƻ��������֡�\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "������̴ľ���ɵĴ����ӣ����Ϻ������棬�����������ɡ�\n"
        ]));
        set( "exits", ([
                "south"  : TROOM"path9",    
                "north"  : TROOM"yard9",
                "up" : TROOM"up_hall",
                "down" : TROOM"down_hall"
        
        ]) );
        hu = new(TMONSTER"huyang");
        hu->move(this_object());
        
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
        ]) );        
        reset();
}
void init()
{
add_action("do_sit","sit");
}
int do_sit(string arg)
{
if ( !arg || arg!="chair") return notify_fail(
"��ʲ��?\n");
if ( !present("hu") ){
   write (
   "�������������̴�����ϣ��о����������������ȥ\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"�����������̴�����ϣ�����ı������۾�\n"
      ,this_player());
}
else {
   write (
   "������������ʱ��������һ��ץ���㣬˵��: �ⲻ����������\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"��Ҫ������Ϣ����ȴ����������ֹ�ˣ�\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
