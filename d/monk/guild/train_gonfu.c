// This is a study object which provides a simple command to let player
// list and train gonfus.
// Created by Layuter @Eastern.Stories (4-10-94)
// Modify by angel for Monk... :) (5-8-94)
// Modify by Kyoko. for 2 types of gonfus. (10-18-94)
#include <mudlib.h>

mapping gonfus;
string type;

// This function setups the type of gonfus that he learn now.
// Now has: fist, heal, general.
void set_gonfu_type(string s)
{
	type = s;
}

// This function setups the gonfus can be learned. The format is:
// ([ <gonfus name> : ({ <skill type>, <skill need>, <exp> }), 
void set_gonfus(mapping s)
{
	gonfus = s;
}

mapping query_gonfus()
{
	return gonfus;
}

// This function checks if a player can learn a certain gonfus. 
int gonfu_exist(string gonfu)
{
	if( !gonfus || !mapp(gonfus) || !gonfu || undefinedp(gonfus[gonfu]) )
		return 0;

	return 1;
}

int check_skill(object player, string gonfu)
{
	if( (int)player->query_perm_skill(gonfus[gonfu][0]) < gonfus[gonfu][1] )
		return 0;
	return 1;
}

// This function returns experience required to raise this gonfu. 
int raise_cost(object player, string gonfu)
{
    int exp;	

	exp = gonfus[gonfu][2]; 
	exp -= exp * ((int)player->query_perm_stat("pie")-15) / 30;
	if( exp < 0 ) exp = 0;
	return exp;
}

// *************************************************************************
// The following are default commands for gonfu rooms. You can alter it in
// your code if you think it is needed.
// *************************************************************************
void init()
{
	add_action( "do_train", "train" );
}

void view_catalog()
{
	mapping gonfus;
	string *s;
	int i, exp,chinese_mode;

	chinese_mode = can_read_chinese();
	printf( "%-31s  %-12s %-7s\n","��ѧ����", "��������", "���輼��ֵ" );
	write( "=====================================================================\n");
	gonfus = query_gonfus();
	s = keys(gonfus);
	for( i=0; i<sizeof(s); i++ ) {
		printf( "%-30s   %5s     %6d\n",
		 to_chinese(s[i]) + " (" + s[i] + ")",
		 to_chinese(gonfus[s[i]][0]),
		gonfus[s[i]][1]);
	}
	write( "=====================================================================\n");
}


int do_train(string arg)
{
	int chinese_mode, exp, tmp;
	string *tmp2;
	object me;

	if( type != "general" && type != "heal" && type != "fist" ) return 0;

	me = this_player();
	chinese_mode = can_read_chinese();
	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ: train <��\������>\n" ); 

	if( type != "general" )
		tmp2 = (string *)me->query("monk_gonfu/"+type);
	if( (type == "general" && !undefinedp(me->query("monk_gonfu/"+arg))) ||
		(tmp2 && member_array(arg, tmp2) != -1) ) {
		write("�����\�����Ѿ�ѧ���ˣ�����Ҫ��ѧһ��!\n");
		return 1;
	}

	if( !gonfu_exist(arg) ) {
		write (	"���Ҳ�����������Ҫѧ�����׹�\��! (������˰�) \n");
		return 1;
	}
	
	if( !check_skill(me, arg) ) {
		write( "��ļ������費�㣬��������������! \n");
		return 1;
	}	

	exp = raise_cost(me, arg);
	tmp = exp - (int)me->query_exp_stock();
	if( tmp > 0 ) {
		write("������Ҫѧ������������Ҫ "+tmp+" �㾭�顣\n");
		return 1;
	}

	write( " *** ����һ�������������ѧ���� "+ to_chinese(arg) + " *** \n");

	if( type == "general" )
		me->set("monk_gonfu/"+arg, 0);
	else {
		if( tmp2 ) tmp2 += ({ arg });
		else tmp2 = ({ arg });
		me->set("monk_gonfu/"+type, tmp2);
	}
	me->gain_experience( -exp );	
	return 1;
}
