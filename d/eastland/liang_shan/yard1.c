#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ͥԺ" );
	set_long(
	"����һ��СС��ͥԺ���������ҵ��ţ�Ũ����ɡ��ľҶ֮���в���ҡҷ��\n"
	"ȴ�Ե���ظ�Ϊ�ž����쳾�е����ַ��������Ѿ�δ��ͥԺ��������һ��СС\n"
	"�Ľ�����������һƬɽ�ڣ���ע�⵽һ����Ѩ���ƺ����˾�����������ӡ���\n"
	"ɽ���ϣ�����һ������(rope)�������������ȥ�����ӡ�\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "no_monster",1);
        set("c_item_desc",(["rope":
"����һ���ϾɵĻ�ɫ�������������ƺ���Щ��ʷ�����ӣ������������ӣ��ƺ���\n"
"���̣�Ҳ��\�������������ɽ���Ͽ����羰\n"            
            ]));        
        set( "exits", ([
                "north"  : TROOM"bed5",
                "cave" : TROOM"cave5",
                "west" : TROOM"path6",
        ]) );
        reset();
}
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
 if ( !arg || arg != "rope")
    return notify_fail(
    "�ۣ���ǿ��ͽ������?\n");
    write (
    "������һ����ץס�����ݣ���������������ɽȥ��\n");
    tell_room(this_object(),
	"�㿴��"+this_player()->query("c_name")+"ץס����, �ñ�׾������������ȥ....\n",
    this_player());
 if ( (int)this_player()->query_skill("climbing")<50+random(8) ) {
    write (
       "��һ����С�ģ���һ����һ���Ӵ�ɽ��ˤ������.....\n");
       this_player()->receive_special_damage("none",20);
       tell_room(this_object(),
	"�㿴��"+this_player()->query("c_name")+"һ����С��, ��������ˤ����, ˤ��ͷ��Ѫ��..\n",
       this_player());
       return 1;
       }
 this_player()->move_player("/d/eastland/liang_shan/cannon","SNEAK");
 tell_room("/d/eastland/liang_shan/cannon",
"�㿴��"+this_player()->query("c_name")+"��������Ĵ�ɽ����������\n",
 this_player());
 return 1;
}    
int clean_up() { return 0; }