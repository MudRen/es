//#pragma save_binary

#include <mudlib.h>
#define BOARD "/d/scholar/scholar/scholar_board.c"

inherit GUILD;

void create()
{
    object guild_master;
	::create();
	set_short("��ī��");
	set_long( @LONG_DESCRIPTION
����������һ���ɫ�������Ժ��һ���ľ����д���������ɷ���Ĵ��֣���֪
����ʲ���˵Ĵ�����������ȷ����һ���ǡ���ī���������֣���������˱���ǳ�
ϲ���ύ���ص�����ī�ͣ���������һ�Ź�����С��(paper)������д���й�����ī
���Ĺ涨��ע�����
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([ 
		"paper" : @LONG_TEXT
����������������������������������������������������������������
��ī����Ҳ�����׳Ƶ��������ᣬ�������ġ����ϳ������������ʳ��
̸���۽��д�ѧ�յĵط���������������ī����Ϊһ�������������
������  5 ����ǻ�(intelligence)�����⣬���϶���ī��������������
����Ϊ�˱��⾪��ʥ�ݣ�����������ò���������������ˡ������ˡ���
������ħ�����ˣ�����л�����롣
����������������������������������������������������������������
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : "/d/eastland/easta/north_malley",
		"up"   : "/d/scholar/scholar/hall" ]) );
	set( "no_monster", 1 );
	guild_master=new("/d/scholar/scholar/monsters/scholar" );
	guild_master->move(this_object());
	BOARD->frog();
	set_guild( "scholar" );
        set( "pre_exit_func", ([
		"up" : "check_scholar" ]) );
        reset();
}

int check_scholar()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="scholar" ) {
                write( "�Բ���, ֻ�������ܽ�ȥ��\n" );
		return 1;
	}
	return 0;
}

int clean_up()
{
		return 0;
}
