#include "saulin_temple.h" 

inherit ROOM;

mixed *gonfu_level_exp;
int do_help(string arg);
void set_gonfu_level_exp();

void create()
{
	::create();
	seteuid( getuid() );
	set_gonfu_level_exp();
	set_short("Training Room", "������ɮ���䷿");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
�㿴��һȺȺ����ɮ�ڴ�ѵ����ѧ���˵���������ɮѵ����ѧ֮������νʦ����
���ţ������ڸ��ˡ����е�������ѧ����ʮ���������ж�ʮ���ؾ��磬��������һ��
��ѧ��һ���̶ȣ����ڴ˵������ɸ��ߵľ��硣��ϸ��˵���뿴ǽ��(wall) 
C_LONG_DESCRIPTION
	);
	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"wall" : @LONG_TEXT
����������������������������������������������������������������
cost              ������ÿ����ѧ������Ҫ��
train <��\������>  �ô�ָ����ѵ����һ����ѧ 

��ĸ�����ѧ��Ϊ�� �ڼ��� �� ��������ֵ ����ʾ�� gonfus �С�
����������������������������������������������������������������
LONG_TEXT
 ]) );

	set( "exits", ([ 
 	    "north" : SAULIN"monk_pass",
    ]));
	reset();
}

void set_gonfu_level_exp()
{
	int exp, i;
	
	exp = MAX_GONFU_EXP;
	gonfu_level_exp = allocate(MAX_GONFU_LEVEL);
	for( i=MAX_GONFU_LEVEL-1; i>=0; i-- ) {
		gonfu_level_exp[i] = exp;
		switch( i ) {
			case  0..1  : exp -= exp /  2; break;
			case  2..5  : exp -= exp /  3; break;
			case  6..10  : exp -= exp /  4; break;
			case  11..17 : exp -= exp /  5; break;
			case  18..25 : exp -= exp /  6; break;
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
	string *needed = ({ "bolo-mi", "chu-han", "fu-mo", "gi-mei", "tai-zuo", 
		"da-mo", "wu-sur", "body-def", "bolo-fist", "dragon-claw", "keep-flower", "power-finger" });
 
	if( !arg ) return do_help("train");
	lvl = (int)this_player()->query("monk_gonfu/"+arg);
	if( member_array(arg, needed) != -1 && undefinedp(lvl) )
		return notify_fail( can_read_chinese()?
			"�㻹�������书\, ����ѵ��?\n":
			"You don't know such a gonfu!\n");

	if( member_array(arg, needed) == -1  ) {
		write(can_read_chinese()?
			"û�������\��!(ֻ��������ѧ����ʮ��������Ҫѵ��Ŷ!ȭ����ҽ���书\����) \n��������������ˣ���֪ͨ��ʦ��\n":
			"You can't train that here, please report to wizard.\n" );
		return 1;
        }

	if( lvl >= MAX_GONFU_LEVEL ) {
		write(can_read_chinese()?
			"���Ѿ���ȫ�˽�"+to_chinese(arg)+"��ѧ�ľ����ˡ�\n":
			"You can't train any more.\n" );
		return 1;
	}

	exp = (int)this_player()->query("gonfus_exp/"+arg);
	need_exp = gonfu_level_exp[lvl];
	if( exp < need_exp ) {
		write(can_read_chinese()?
			"�㻹��Ҫ "+(need_exp-exp)+" �㾭���������"+
			to_chinese(arg)+"����ѧ���硣\n" :
			"You need more "+(need_exp-exp)+" to advance your "+arg+" gonfu.\n"
		);
		return 1;
	} else {
		this_player()->set("monk_gonfu/"+arg, lvl+1);
		write(can_read_chinese()?
			"����һ������, �� "+to_chinese(arg)+" ��ѧ�ľ��������ˡ�\n":
			"Your practiced of "+arg+" increases.\n"
		);
		return 1;
	}
}

int do_cost()
{
	int i;
	write( can_read_chinese()? "���������书\����Ҫ����������ֵ\n":"");
	for( i=0; i<MAX_GONFU_LEVEL; i++ ) {
	  if( can_read_chinese() )

 printf("��%2d�ؾ���: %8d ���������顣%s",i+1,gonfu_level_exp[i],(i%2?"\n":"\t") );
	  else
	    printf("  Level %2d : %15d experiences��\n",i+1,gonfu_level_exp[i]);
	}
 printf("\n\n");
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
