#include <mudlib.h>
#include "../scholar.h"

inherit ROOM;

mixed *gonfu_level_exp;
int do_help(string arg);
void set_gonfu_level_exp();

void create()
{
	::create();
	seteuid( getuid() );
	set_gonfu_level_exp();
	set_short("Training Room", "������");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
������ī���Ķ�����, ��Ի����������������ѧ��������ϰ��ʫ������һ��
��������������ϰ��������... ������������Զ���(train) �������书\������
�ȡ�
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/scholar/scholar/hall" ]) );
	reset();
}

void set_gonfu_level_exp()
{
	int exp, i;
	
	exp = MAX_GONFU_EXP;
	gonfu_level_exp = allocate(MAX_GONFU_LVL);
	for( i=MAX_GONFU_LVL-1; i>=0; i-- ) {
		gonfu_level_exp[i] = exp;
		switch( i ) {
			case  0..1  : exp -= exp /  2; break;
			case  2..5  : exp -= exp /  3; break;
			case  6..9  : exp -= exp /  4; break;
			case 10..19 : exp -= exp /  5; break;
			case 20..29 : exp -= exp /  6; break;
                        case 30..35 : exp -= exp /  7; break;
			default : break;
		}
	}
}

void init()
{
	add_action("do_advance", "train");
	add_action("do_cost", "cost");
	add_action("do_help", "help");
}

int do_advance(string arg)
{
	int need_exp, exp, lvl, i;
	string *needed = ({ "song", "tang", "han", "mar_short", 
	                    "couples_sword" });
	
	if( !arg ) return do_help("train");
	lvl = (int)this_player()->query("scholar_gonfu/"+arg);
	if( undefinedp(lvl) )
		return notify_fail("�㻹�������书\, ������ϰ?\n" );

	if( member_array(arg, needed) == -1 || lvl >= MAX_GONFU_LVL ) {
		write("���Ѿ���ȫ�˽�"+to_chinese(arg)+"�İ����ˡ�\n");
		return 1;
	}

	exp = (int)this_player()->query("gonfus_exp/"+arg);
	need_exp = gonfu_level_exp[lvl];
	if( exp < need_exp ) {
		write(can_read_chinese()?
			"�㻹��Ҫ "+(need_exp-exp)+" �㾭���������"+
			to_chinese(arg)+"�������ȼ���\n" :
			"You need more "+(need_exp-exp)+" to advance your "+arg+" gonfu.\n"
		);
		return 1;
	} else {
		this_player()->set("scholar_gonfu/"+arg, lvl+1);
		write(can_read_chinese()?
			"����һ������, �� "+to_chinese(arg)+" �������������ˡ�\n":
			"Your practiced of "+arg+" increases.\n"
		);
		return 1;
	}
}

int do_cost()
{
	int i;
	write( "���������书����Ҫ����������...\n");
	for( i=0; i<MAX_GONFU_LVL; i++ ) {
	  if( can_read_chinese() )
	    printf("  �����ȼ� %2d : %15d ���������顣\n",i+1,gonfu_level_exp[i]);
	  else
	    printf("  Level %2d : %15d experiences��\n",i+1,gonfu_level_exp[i]);
	}
	return 1;
}

int do_help(string arg)
{
	if( !arg || arg != "train" ) return 0;
	write("Syntax: train <gonfu name>\n\n"
		"The command let you train your practiced of gonfus you know.\n"
		"Type cost to see how many experiences needed for each level.\n");
	return 1;
}
