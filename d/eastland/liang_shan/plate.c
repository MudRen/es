#include <takeda.h>

inherit ROOM;

void create()
{
	object ling;
	::create();
	set_short( "�㽫̨" );
	set_long(
	"��������ɽ���ĵ㽫̨��վ�������ǰ�������䳡��һ�����ţ����\n"
	"������̨�²����󷨡��Ի͵����Ĵ�ӵ��һ�����ɸ�̨��̨���������ƣ�\n"
	"�������С�̨��һ��ǧ��޶������Ƶ����ƣ����ǴӶ���Ʈ�����ģ�����\n"
	"��������ʮ������̴���Ρ�һ��ȫ����װ�������ˣ��������ϣ�׿����ͭ\n"
	"��ǰ����ע����̨�¡�\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "�����������Щ����ʱ���ֳ�����ĵ�����һ�ۣ��㼱æ��Ŀ��ת��̨�¡�\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "south"  : TROOM"plaza5",    
                "north"  : TROOM"path5",
        ]) );
        ling = new(TMONSTER"lin");
        ling->move(this_object());
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
if ( ! present("lin") ){
   write (
   "�������������̴�����ϣ��о����������������ȥ\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"�����������̴�����ϣ�����ı������۾�\n"
      ,this_player());
}
else {
   write (
   "������������ʱ���ֳ�����ɰ���ì��ס�����ģ�˵��: �ⲻ����������\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"��Ҫ������Ϣ����ȴ���ֳ���ֹ�ˣ�\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
