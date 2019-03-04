//#pragma save_binary

// guild.c
// Written by Mobydick@TMI-2, 11-15-92
// Almost rewritten by Annihilator@Eastern.Stories, 10-26-93
// Please leave the credits part of this header in place.
// You can delete the rest of it.

#include <daemons.h>
#include <stats.h>
#include <explore.h>
#include <mudlib.h>
#include <move.h>
#include <guilds.h>

inherit ROOM;

// The variable trainable_skills stores the skills which this guild can
// train you in.

string this_guild;

//void set_guild(string class);
void set_guild(string guild);
void announce_guild_members(string type, object me);

int do_list(string arg);
int do_cost(string arg);
int do_advance(string arg);
int do_train(string arg);
int do_help(string arg);
int do_explore(string area);

// This function announce all member of this guild some message.
void announce_guild_members(string type, object me)
{
	string *master, class1, c_msg;
	object *urs;
	int i;
	
	urs = users();
	master = this_guild->query_guild_master();
	if( !master ) master = ({ "Master", "�����ϴ�" });
	class1 = (string)me->query("class");
	c_msg = "["+to_chinese(class1)+"] "+master[1]+" : ";
	if( type == "join" ) {
		c_msg += "��ӭ "+me->query("c_name")+"("+me->query("name")+") "+
		  "��ʽ�������ǵ�����!\n";
	} else return;
	for( i=0; i<sizeof(urs); i++ )
		if( this_guild->is_guild_member(urs[i]) )
			urs[i]->quick_message(c_msg);
}

// This function sets the classes that are allowed to train/advance in
// the guild. If you pass the string argument ALL, then all classes can
// train/advance here. Otherwise, you should pass an array of strings 
// containing the names of classes that are allowed to train/advance
// in this guild.

void set_guild(string guild)
{
	if( file_size(guild)>0 )
		this_guild = guild;
	else
		this_guild = GUILD_MASTER(guild);
}

// Init adds the cost and train commands. You must call this if you
// add your own init functions. (i.e. you must call guild::init();
// in the init() of your guild.

void init()
{
	add_action("do_cost", "cost");
	add_action("do_list", "list");
	add_action("do_advance", "advance");
	add_action("do_train", "train");
	add_action("do_join", "join");
	add_action("do_verify", "verify");
	add_action("do_help", "help");
	add_action("do_explore", "explore");
	add_action("do_quests", "quests");
}

int do_list(string arg)
{
	int i;
	string msg, *skills;

	skills = this_guild->query_skill_list();
	msg = "������������ѵ���ļ�����:\n";
	for( i=0; i<sizeof(skills); i++)
			msg += sprintf("    %-30s ( ����ֵ���� = %3d%%, ���� = %3d )\n", 
				to_chinese(skills[i]) + "("+skills[i]+")",
				this_guild->query_skill_cost(skills[i]),
				this_guild->query_skill_max(skills[i]) );
	write(msg);
	return 1;
}

int do_cost(string arg)
{
	int i, exp, lvl, s, stock, none;
	string *attrs, *skills, msg;
	object me;

	me = this_player();
	if( !this_guild->is_guild_member(me) )
		return notify_fail("�ܱ�Ǹ���㲻���������ĳ�Ա��\n");

	lvl = me->query_level();
	exp = (int)STATS_D->query_level_exp( lvl )
		  - (int)me->query_experience();

	if( lvl >= MAX_PLAYER_LEVEL ) msg ="���Ѿ�������߼��ˡ�\n";
	else if( exp > 0 ) msg ="�㻹��Ҫ "+exp+" �㾭�����������\n";
	else msg = "��ľ���ֵ�Ѿ��ﵽ������׼�ˡ�\n";
		
	stock = (int)me->query_exp_stock();
	if( stock < 1 ) 
		msg +="��Ŀǰû���κζ���ľ�������������������뼼�ܡ�\n";
	else {
	    none = 1;
		msg +="�������� "+stock+" �㾭������������������뼼�ܡ�\n";

		msg +="�������� :";
		attrs = STATS_D->query_stat_names();
		for( i=0; i<sizeof(attrs); i++) {
			s = (int)me->query_perm_stat(attrs[i]);
			if( s >= (int)this_guild->query_stat_max(attrs[i]) ) continue;
			exp = (int)me->query_stat_exp_cost(attrs[i], s);
			if( exp > 0 ) {
			    none = 0;
				msg += sprintf("\n    %30-s -> %2d    %d �㾭�顣",
					to_chinese(attrs[i]) +"("+ attrs[i] +")", s+1, exp );
			}
		}
        if( none )
          msg += " ������Ծ��Ѵﱾ�������ֵ�ˡ�\n";
        else msg += "\n";
        none = 1;
		msg += "ѵ������ :";
		skills = this_guild->query_skill_list();
		for( i=0; i<sizeof(skills); i++) {
			s = (int)me->query_perm_skill(skills[i]);
			exp = this_guild->query_skill_exp_cost(skills[i], s);
			if( exp > 0 ) {
			    none = 0;
				msg +=sprintf("\n    %30-s -> %2d    %d �㾭�顣",
					      to_chinese(skills[i])+"("+skills[i]+")", s+1, exp) ;
			}
		}
		if( none )
          msg +=" ��ļ��ܾ��Ѵﱾ�������ֵ�ˡ�\n" ;
        else msg += "\n";
	}
	write(msg);
	return 1;
}

int check_total_stats_is_max(object player)
{
    int i, level, total_stat, max_total_stat;
    string *attrs;
    
    level = (int)player->query_level();
    total_stat = 0;
    max_total_stat = 6 + level * 8;
    attrs = STATS_D->query_stat_names();
    for( i=0; i<sizeof(attrs); i++ )
    	total_stat += (int)player->query_perm_stat(attrs[i]);
    if( total_stat < max_total_stat ) return 0;
    else return 1;
}

int do_advance(string arg)
{
    mapping quests;
	int lvl, stat, exp, chinese_mode;
	object me;
	string *attrs;

	me = this_player();
	chinese_mode = can_read_chinese();

      if( me->id("guest") )
              return notify_fail("�ܱ�Ǹ, GUEST ���������κεȼ���\n") ;
              
	if( !this_guild->is_guild_member(me) )
		return notify_fail("�ܱ�Ǹ���㲻���������ĳ�Ա��\n");

	if( this_guild == "/d/adventurer/adventurer" && 
		(string)me->query("class") != "adventurer" ) {
		return notify_fail(
			"���Ѿ������������Ĺ��ᣬ���������������ȼ������ԡ�\n");
	}
	
	// prevent wrong keyin, added by Kyoko.
	if( !arg ) return do_help("advance");
	
	// Advance attribute?
	if( arg && arg != "level" && arg != "wizard" && arg != "guild" ) {
		stat = (int)me->query_perm_stat(arg);
		if( !stat ) return do_help("advance");
		arg = STATS_D->check_stat_name(arg);
		if( stat >= (int)this_guild->query_stat_max(arg) )
			return notify_fail(
				sprintf("���%s(%s)�Ѿ��ﵽ���ֵ�ˡ�\n",to_chinese(arg),arg));

		exp = (int)me->query_stat_exp_cost( arg, stat );
		if( exp > (int)me->query_exp_stock() )
			return notify_fail("��ľ���ֵ������\n");
		if( check_total_stats_is_max(me) )
			return notify_fail("�Բ�������ĵȼ�������ֻ�ܼӵ�����������������ĵȼ���\n");
		if( STATS_D->advance_stat(me, arg) ) {
			me->gain_experience( -exp );
				printf("���%s(%s)������������ %d��\n", to_chinese(arg),arg, me->query_stat(arg));
			return 1;
		} else
			return do_help("advance");
	}

	if( arg == "level" || arg == "wizard" ) {
		lvl = (int)me->query_level();
		if( lvl >= MAX_PLAYER_LEVEL )
			return notify_fail("���Ѿ�������߼��ˡ�\n");
			
		// if level = 19 and advance level again ....	
		if( arg != "wizard" && (lvl+1) >= MAX_PLAYER_LEVEL )
		return notify_fail("���Ѿ�������߼��ˡ�\n");
		// check exp...
		exp = (int)STATS_D->query_level_exp(lvl);
		if( exp > (int)me->query_experience() )
			return notify_fail("��ľ���ֵ������������׼��\n");

		// check quest point, added by Kyoko.
		if( !QUEST_D->check_quest(me) )
			return notify_fail("��Ǹ, ����������������������׼��\n");

		// check explored, add by Kyoko.
			if( !EXPLORE_D->check_explore(me) )
			return notify_fail("��Ǹ, ���̽�նȻ�δ�ﵽ������׼���ٶ�ȥ���ɡ�\n");

		// if advance wizard ...
		if( arg == "wizard" ) {
	    	if( lvl < 19 || !EXPLORE_D->check_explore(me) ||
	        	!QUEST_D->check_quest(me) )
	        	return notify_fail("��Ŀǰ�������ʸ����ɼ�ϰ��ʦ��\n" );
		}

		STATS_D->advance_level(me);
		write(sprintf("�������ǵ� %d ���ˡ�\n",me->query_level()));
		me->set("title",me->query_title());
		tell_room( environment(me), 
			sprintf("%s�����ǵ� %d ���ˡ�\n",me->query("c_name"),me->query_level()) ,
			me
			  );
		return 1;
	}
}

int do_train(string arg)
{
	int exp, skill;
	object me;

	me = this_player();
	if( !this_guild->is_guild_member(me) )
		return notify_fail("�ܱ�Ǹ���㲻���������ĳ�Ա��\n");

	if( !arg || !this_guild->query_skill_exp_cost(arg,0) )
		return notify_fail("���� list ָ��쿴���������ṩ��ѵ�����ݡ�\n");

	skill = (int)me->query_perm_skill(arg);
	exp = this_guild->query_skill_exp_cost(arg, skill);

	if( exp < 1 )
		return notify_fail("���"+to_chinese(arg)+"�����Ѿ��ﵽ���ֵ�ˡ�\n");

	if( exp > (int)me->query_exp_stock() )
		return notify_fail("��ľ���ֵ������\n");

	if( skill >= ((int)me->query_level() * 5 + 5) )
		return notify_fail("�ܱ�Ǹ����Ŀǰ�ĵȼ�ֻ��ѵ����Ŀǰ���ֵز���\n");

	me->gain_experience( -exp );
	STATS_D->train_skill( me, arg );
		printf( "���%s�������������� %d �ˡ�\n", to_chinese(arg), me->query_perm_skill(arg));
	return 1;
}

int do_join(string arg)
{
	object ob, token;
	int join_ok;

	if( arg ) return 0;

	ob = this_player();
	if( this_guild->is_guild_member(ob) )
		return notify_fail("���Ѿ��Ǳ�����ĳ�Ա�ˣ�\n");
	
	if( ob->id("guest") )
	      return notify_fail("Guest ���ܼ����κι��ᡣ\n") ;

	// Check if the player is a wizard or didn't join other guilds yet.
	if( wizardp(ob) || ( (string)ob->query("class")=="adventurer" 
	    && (int)ob->query_level() < 5 ) ) {
		join_ok = (int)this_guild->join_player(ob);
		if( join_ok ) {
		  announce_guild_members("join", ob);
		  ob->set("title",ob->query_title());
		}
		return join_ok;
	} else 
		return notify_fail( "���Ѿ����������������ˣ��������˳�ԭ���Ĺ��ᣡ\n");
}

int do_verify()
{
	notify_fail("�Բ����㲻���������ĳ�Ա��\n");
	return (int)this_guild->check_token( this_player() );
}

int do_explore(string arg)
{
	int expl, max, i, need_exp;
	object me;
	
	me = this_player();
	need_exp = ((int)me->query_level()-3)*3 ;
	if( need_exp < 0 ) need_exp = 0;
	if( !this_guild->is_guild_member(me) )
		return notify_fail("�ܱ�Ǹ�����ﲢû��������ϣ���ص��Լ��Ĺ����ѯ̽�նȡ�\n");

	for( i=0; i<sizeof(AREAS); i++ ) {
		expl = (int)me->query_explore_points(AREAS[i]);
		max = (int)EXPLORE_D->query_total_explore(AREAS[i]);
		if( max < 1 ) continue;
		expl = expl * 1000 / max;
		if( expl > 1000 ) expl = 1000;
		printf("���� : "+set_color("%13s", "HIG")+"    ̽�ն� : "+
			set_color("%2d.%1-d%%", "HIY")+"  ������׼ : %3d%%\n",
			to_chinese(AREAS[i]), expl/10, expl%10,need_exp);
	}
	expl = (int)me->query_explore_points();
	max = (int)EXPLORE_D->query_total_explore();
	if( max < 1 ) expl = 0;
	else expl = expl * 1000 / max;
	if( expl > 1000 ) expl = 1000;
	printf(set_color("ƽ��̽�ն� : %2d.%1-d%%.\n","HIC"), expl/10, expl%10);
    return 1;
}

int do_quests(string arg)
{
	string *sloved;
	int i,size_quest;
	object me;

	me = this_player();
	if( !this_guild->is_guild_member(me) )
		return notify_fail("�ܱ�Ǹ�����ﲢû��������ϣ���ص��Լ��Ĺ����ѯ��\n");

	sloved = me->query_finish_quests();
	if( !sloved || !( size_quest=sizeof(sloved) ) )
		write(set_color("��Ŀǰ��δ����κε�����, �ӵ��Ͱ�!\n", "HIR"));
	else {
		for( i=0; i<size_quest; i++ )
			printf("������� "+set_color("%s", "HIG")+
				   " ������\n", to_chinese( sloved[i] ) );
		printf( "���õ� %3d ������������\n" ,(int)me->query_quest_points());
	}
    return 1;
}

int do_help(string arg)
{

	switch(arg) {
		case "guild": write( @C_USAGE_GUILD
�����������ʹ�����µ�ָ�ÿһ��ָ��и��꾡��˵��( ���� "help <ָ��>" ):

  list        - �г������������ܽ���ѵ���ļ�����Ŀ��
  cost        - �г��������������ԡ���ѵ����������ľ���ֵ��
  advance     - �����ȼ�, ����ȼ������ԡ�
  train       - ѵ�����ܡ�
  join        - ����������ᣬ��ĵȼ�����С� 5 �����ܼ��빫�ᡣ
  verify      - ȷ����֣���ȡ����ʧ�Ĺ������
  explore     - ��Ѱ��Ŀǰ��ð�նȡ�
  quests      - �г�����ɵ���������

C_USAGE_GUILD
			); break;
		case "list": write( @USAGE_LIST
ָ���ʽ: list

    ���ָ�����г������������ܽ���ѵ���ļ�����Ŀ��
USAGE_LIST
			); break;
		case "cost": write( @USAGE_COST
ָ���ʽ: cost

    ���ָ������ʾ�������������ԡ���ѵ����������ľ���ֵ��
USAGE_COST
			); break;
		case "advance" : write( @USAGE_ADVANCE
ָ���ʽ: advance [ str | int | dex | con | pie | kar | level | wizard ]

    ����ľ���ֵ�㹻ʱ�����ָ����������ĵȼ�������ȼ��������ԡ����ǣ�
������̽�նȼ��������δ���׼ʱ����ʹ����ֵ�㹻�಻��������
USAGE_ADVANCE
			); break;
		case "train": write( @USAGE_TRAIN
ָ���ʽ: train <����>

    ����ӵ���㹻�ľ���ֵʱ�����ָ����������ļ��ܡ�
USAGE_TRAIN
			); break;
		case "join": write( @USAGE_JOIN
ָ���ʽ: join

    ���ָ�����������������ᡣ����Ҫע����ǣ�ĳЩ�������ǰ�������Ҫ
��߱�ĳЩ�ض���������������ָ�info�����õ��й���������һЩ��Ѷ��
USAGE_JOIN
			); break;
		case "info": write( @USAGE_INFO
ָ���ʽ: info [<����>]

    ���ָ���ܸ���һЩ�й�����������õ���Ѷ�����������������һ������ǰ
��һ��Ҫ���Ķ���Щ��Ѷ������ָ�info������û��ָ������Ļ��������һ��
����������б�
USAGE_INFO
			); break;
        case "explore": write( @USAGE_EXPLORE
ָ���ʽ: explore

    ���ָ���ܲ�Ѱ��Ŀǰ��ð�նȡ�
USAGE_EXPLORE
			); break;
        case "quests": write( @USAGE_QUESTS
ָ���ʽ: quests

    ���ָ�����г�������ɵ���������
USAGE_QUESTS
			); break;
		default:
			return 0;
	}
	return 1;
}
