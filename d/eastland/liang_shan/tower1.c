#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����̨" );
	set_long(
	"��������ɽ��ɽկ������̨���ôִ����ľ�ܳɣ���Ȼǿ�粻�ϣ�\n"
	"վ��������Ȼ����ƽ�أ��������һ̨ǧ�ﾵ(telescope)��\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );
        set("c_item_desc",(["telescope":
"����Ĭ��˹�۹�������ǧ�ﾵ��͸�����ɿ�����Զ�ĵط����������\n"
"ɽ���ĺú���������Ŀǰ���������Ĺ��ǵķ����Ա���ӹٱ�������\n"
"Ҳ�����������ȥʹ��(use)����\n"            
            ]));        
        set( "exits", ([
                "down" : TROOM"wall8"
        ]) );
        set( "objects",([
                "lu":TMONSTER"lu",
                "bandit":TMONSTER"small_bandit",
                "captain":TMONSTER"captain"
                ]));
        reset();
}
void init()
{
     add_action("do_use","use");
}
int do_use(string arg)
{
 if ( !arg || arg != "telescope")
    return notify_fail(
    "��ʲ��?\n");
    write (
    "�㽫�۾��ս�ǧ�ﾵ���Ĺ��Ƿ������нָ��������ǰ��\n");
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_cap_name")+ "ʹ��ǧ�ﾵ������¶������˼��ı���\n" ,
    this_player());
return 1;
}
int clean_up() { return 0; }    