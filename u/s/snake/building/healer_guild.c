//#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <guilds.h>

#define BOARD "/d/healer/building/healer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;
    
	::create();
	
    set_short("��ҽ�߹���");
	set_long( 
		 @C_LONG_DESCRIPTION
������������һ��������ۼ�Ķ���ʽ�����������Ĵ�������һ����̴ľ
���Ҷ����д������������������������ɳ�۵���ҽ�߹��ᣬ��Ȼ���ﲼ
�õ��൱�������������еľ��Ѷ����ɸ����ܹ������������ϵ��չ˵ľ���
��ģ��㿴���м�һ�������Ϲ���һ������(sign)������ĳ������������
, ������������ҽ�ߴ���֪ʶ��ʥ�ء�
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
		"sign" : @LONG_TEXT
����������������������������������������������������������������������
������д��:
    ������ֻ����־��ҽ���˵������ˣ����֮���м����鷸�ơ���ɱ�޹�����
��Υ�߽������ǽ,��Զ����̤��˵�һ������ϸ����������� help guild ��
��˵����
    �йر�������������������� help healers��
����������������������������������������������������������������������
LONG_TEXT
 ]) );
    set( "exits", ([ 
                "north": "/d/healer/building/healer_shop",
		        "east" : "/d/healer/building/healer_inner",
		        "west" : "/d/noden/bluesand/alley2",
		        "south": "/d/healer/building/healer_operate",
	]) );

	set( "pre_exit_func", ([
		"east" : "check_healer" ]) );
    guild_master=new("/d/healer/building/monsters/healer");
    guild_master->move(this_object());
	create_door( "west", "east", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "����",
		"desc" : "A red arch door which decorated with bronze rings",
		"c_desc" : "һ�Ⱥ�ɫ�Ĺ��ţ�����װ�������ͭ����\n",
		"status" : "closed"
	]) );
	set_guild( "healer" );
	BOARD->frog();
	reset();
}

int clean_up() {  return 0; }

int check_healer()
{
	if( wizardp(this_player()) ) return 0;
	if( !call_other(GUILD_MASTER("healer"), "is_guild_member", this_player() ) ) {
		write( "�㲻����ҽ�ߣ����ܽ��붫�ߵ��鷿��\n" );
		return 1;
	}
	if( (int)this_player()->query("alignment") < -200 ) {
		write( "������̫�໵�£�����Ĺ�����֮ǰ���ܽ��붫�ߵ��鷿��\n"
 );
		return 1;
	}
	return 0;
}
