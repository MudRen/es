#include "../mage.h"

inherit ROOM;

mixed *spell_level_exp ;
int do_help(string arg);
void set_spell_level_exp();

void create()
{
	::create();
	seteuid( getuid() );
	set_spell_level_exp();
	set_short("Spell Lab", "ħ���о���");
	set_long(@C_LONG_DESCRIPTION
������ɫ֮����ר���о�ħ�����о���, ����������Խ���ʹ�÷������ĵ���
һ���������㿴��һ���ŵ�����, һЩ����ħ��ʦ��һ�������ﲢ���Լ����ĵ�
д���Լ���ħ�����ϡ�������������������ħ�����ĵ�, ����(advance) ���ħ
�������ȡ�
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"north" : MAGE"library" ]) );
	reset();
}

void set_spell_level_exp()
{
	int exp, i;
	
	exp = MAX_GUILD_EXP;
	spell_level_exp = allocate(MAX_GUILD_LVL);
	for( i=MAX_GUILD_LVL-1; i>=0; i-- ) {
		spell_level_exp[i] = exp;
		switch( i ) {
			case  0..1  : exp -= exp /  2; break;
			case  2..5  : exp -= exp /  3; break;
			case  6..9  : exp -= exp /  4; break;
			case 10..19 : exp -= exp /  5; break;
			case 20..29 : exp -= exp /  6; break;
			case 30..39 : exp -= exp /  7; break;
			case 40..49 : exp -= exp /  8; break;
			case 50..59 : exp -= exp /  5; break;
			default : break;
		}
	}
}

void init()
{
	add_action("do_advance", "advance");
	add_action("do_cost", "cost");
	add_action("do_help", "help");
}

int do_advance(string arg)
{
	int need_exp, exp, lvl, i;
	mapping spell_lvls;
	string *types;
	
	if( !arg ) return do_help("advance");
	if( member_array(arg, MAGIC_TYPES) == -1 ) 
		return notify_fail("û������ħ�����ࡣ\n");
	lvl = (int)this_player()->query("spell_levels/"+arg);
	exp = (int)this_player()->query("spell_exps/"+arg);
	if( lvl >= MAX_GUILD_LVL ) {
		write(sprintf("���Ѿ���ȫ�˽�%s�İ����ˡ�\n",to_chinese(arg)));
		return 1;
	}
	need_exp = spell_level_exp[lvl];
	if( exp < need_exp ) {
		write(sprintf("�㻹��Ҫ %d ��%s�����������%s�������ȼ���\n" ,
			(need_exp-exp),to_chinese(arg),to_chinese(arg)));
		return 1;
	} else {
		this_player()->set("spell_levels/"+arg, lvl+1);
		lvl = 0;
		for( i=0; i<sizeof(MAGIC_TYPES); i++)
			lvl += this_player()->query("spell_levels/"+MAGIC_TYPES[i]);
		lvl /= (sizeof(MAGIC_TYPES));
		this_player()->set("spell_levels/guild", lvl);
		write(sprintf("����һ������, �㽫���%s���ĵ���ϸ��д��ħ�����ϡ�\n",to_chinese(arg)));
		return 1;
	}
}

int do_cost()
{
	int i;
	write("��������ħ�������ȼ������ħ������...\n");
	for( i=0; i<MAX_GUILD_LVL; i++ ) {
		printf("  ħ�������ȼ� %2d : %15d ��ħ�����顣\n",i+1,spell_level_exp[i]);
	}
	return 1;
}

int do_help(string arg)
{
	if( !arg || arg != "advance" ) return 0;
	write(@HELP
Syntax: advance [ elemental | black-magic | misc ]

The command raise your magic level on 3 magic type.
Type cost to see how many experiences needed for each level.
HELP
);
	return 1;
}
