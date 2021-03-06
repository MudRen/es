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

void set_guild(string guild);

int do_list(string arg);
int do_cost(string arg);
int do_advance(string arg);
int do_train(string arg);
int do_help(string arg);
int do_explore(string area);

// This function announce all member of this guild some message.
void announce_guild_members(string type, object me)
{
	string *master, gclass, c_msg;
	object *urs;
	int i;
	
	urs = users();
	master = this_guild->query_guild_master();
	if( !master ) master = ({ "Master", "公会老大" });
	gclass = (string)me->query("class");
	c_msg = "["+to_chinese(gclass)+"] "+master[1]+" : ";
	if( type == "join" ) {
		c_msg += "欢迎 "+me->query("c_name")+"("+me->query("name")+") "+
		  "正式加入我们的行列!\n";
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
	msg = "在这里你所能训练的技能有:\n";
	for( i=0; i<sizeof(skills); i++)
			msg += sprintf("    %-30s ( 经验值比例 = %3d%%, 上限 = %3d )\n", 
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
		return notify_fail("很抱歉，你不是这个公会的成员。\n");

	lvl = me->query_level();
	exp = (int)STATS_D->query_level_exp( lvl )
		  - (int)me->query_experience();

	if( lvl >= MAX_PLAYER_LEVEL ) msg ="你已经升到最高级了。\n";
	else if( exp > 0 ) msg ="你还需要 "+exp+" 点经验才能升级。\n";
	else msg = "你的经验值已经达到升级标准了。\n";
		
	stock = (int)me->query_exp_stock();
	if( stock < 1 ) 
		msg +="你目前没有任何额外的经验可以用来提升属性与技能。\n";
	else {
	    none = 1;
		msg +="并且你有 "+stock+" 点经验可以用来提升属性与技能。\n";

		msg +="提升属性 :";
		attrs = STATS_D->query_stat_names();
		for( i=0; i<sizeof(attrs); i++) {
			s = (int)me->query_perm_stat(attrs[i]);
			if( s >= (int)this_guild->query_stat_max(attrs[i]) ) continue;
			exp = (int)me->query_stat_exp_cost(attrs[i], s);
			if( exp > 0 ) {
			    none = 0;
				msg += sprintf("\n    %30-s -> %2d    %d 点经验。",
					to_chinese(attrs[i]) +"("+ attrs[i] +")", s+1, exp );
			}
		}
        if( none )
          msg += " 你的属性均已达本公会最大值了。\n";
        else msg += "\n";
        none = 1;
		msg += "训练技能 :";
		skills = this_guild->query_skill_list();
		for( i=0; i<sizeof(skills); i++) {
			s = (int)me->query_perm_skill(skills[i]);
			exp = this_guild->query_skill_exp_cost(skills[i], s);
			if( exp > 0 ) {
			    none = 0;
				msg +=sprintf("\n    %30-s -> %2d    %d 点经验。",
					      to_chinese(skills[i])+"("+skills[i]+")", s+1, exp) ;
			}
		}
		if( none )
          msg +=" 你的技能均已达本公会最大值了。\n" ;
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
              return notify_fail("很抱歉, GUEST 不能提升任何等级。\n") ;
              
	if( !this_guild->is_guild_member(me) )
		return notify_fail("很抱歉，你不是这个公会的成员。\n");

	if( this_guild == "/d/adventurer/adventurer" && 
		(string)me->query("class") != "adventurer" ) {
		return notify_fail(
			"你已经加入了其他的公会，不能在这里提升等级或属性。\n");
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
				sprintf("你的%s(%s)已经达到最大值了。\n",to_chinese(arg),arg));

		exp = (int)me->query_stat_exp_cost( arg, stat );
		if( exp > (int)me->query_exp_stock() )
			return notify_fail("你的经验值不够。\n");
		if( check_total_stats_is_max(me) )
			return notify_fail("对不起，依你的等级，属性只能加到这样。请先提升你的等级。\n");
		if( STATS_D->advance_stat(me, arg) ) {
			me->gain_experience( -exp );
				printf("你的%s(%s)现在提升到了 %d。\n", to_chinese(arg),arg, me->query_stat(arg));
			return 1;
		} else
			return do_help("advance");
	}

	if( arg == "level" || arg == "wizard" ) {
		lvl = (int)me->query_level();
		if( lvl >= MAX_PLAYER_LEVEL )
			return notify_fail("你已经升到最高级了。\n");
			
		// if level = 19 and advance level again ....	
		if( arg != "wizard" && (lvl+1) >= MAX_PLAYER_LEVEL )
		return notify_fail("你已经升到最高级了。\n");
		// check exp...
		exp = (int)STATS_D->query_level_exp(lvl);
		if( exp > (int)me->query_experience() )
			return notify_fail("你的经验值还不到升级标准。\n");

		// check quest point, added by Kyoko.
		if( !QUEST_D->check_quest(me) )
			return notify_fail("抱歉, 你的任务点数还不到升级标准。\n");

		// check explored, add by Kyoko.
			if( !EXPLORE_D->check_explore(me) )
			return notify_fail("抱歉, 你的探险度还未达到升级标准，再多去逛逛吧。\n");

		// if advance wizard ...
		if( arg == "wizard" ) {
	    	if( lvl < 19 || !EXPLORE_D->check_explore(me) ||
	        	!QUEST_D->check_quest(me) )
	        	return notify_fail("你目前还不够资格升成见习巫师。\n" );
		}

		STATS_D->advance_level(me);
		write(sprintf("你现在是第 %d 级了。\n",me->query_level()));
		me->set("title",me->query_title());
		tell_room( environment(me), 
			sprintf("%s现在是第 %d 级了。\n",me->query("c_name"),me->query_level()) ,
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
		return notify_fail("很抱歉，你不是这个公会的成员。\n");

	if( !arg || !this_guild->query_skill_exp_cost(arg,0) )
		return notify_fail("请用 list 指令察看这里所能提供的训练内容。\n");

	skill = (int)me->query_perm_skill(arg);
	exp = this_guild->query_skill_exp_cost(arg, skill);

	if( exp < 1 )
		return notify_fail("你的"+to_chinese(arg)+"技能已经达到最大值了。\n");

	if( exp > (int)me->query_exp_stock() )
		return notify_fail("你的经验值不够。\n");

	if( skill >= ((int)me->query_level() * 5 + 5) )
		return notify_fail("很抱歉，你目前的等级只能训练到目前这种地步。\n");

	me->gain_experience( -exp );
	STATS_D->train_skill( me, arg );
		printf( "你的%s技能现在提升到 %d 了。\n", to_chinese(arg), me->query_perm_skill(arg));
	return 1;
}

int do_join(string arg)
{
	object ob, token;
	int join_ok;

	if( arg ) return 0;

	ob = this_player();
	if( this_guild->is_guild_member(ob) )
		return notify_fail("你已经是本公会的成员了！\n");
	
	if( ob->id("guest") )
	      return notify_fail("Guest 不能加入任何公会。\n") ;

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
		return notify_fail( "你已经加入了其它公会了，请你先退出原来的公会！\n");
}

int do_verify()
{
	notify_fail("对不起，你不是这个公会的成员。\n");
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
		return notify_fail("很抱歉，这里并没有你的资料，请回到自己的公会查询探险度。\n");

	for( i=0; i<sizeof(AREAS); i++ ) {
		expl = (int)me->query_explore_points(AREAS[i]);
		max = (int)EXPLORE_D->query_total_explore(AREAS[i]);
		if( max < 1 ) continue;
		expl = expl * 1000 / max;
		if( expl > 1000 ) expl = 1000;
		printf("区域 : "+set_color("%13s", "HIG")+"    探险度 : "+
			set_color("%2d.%1-d%%", "HIY")+"  升级标准 : %3d%%\n",
			to_chinese(AREAS[i]), expl/10, expl%10,need_exp);
	}
	expl = (int)me->query_explore_points();
	max = (int)EXPLORE_D->query_total_explore();
	if( max < 1 ) expl = 0;
	else expl = expl * 1000 / max;
	if( expl > 1000 ) expl = 1000;
	printf(set_color("平均探险度 : %2d.%1-d%%.\n","HIC"), expl/10, expl%10);
    return 1;
}

int do_quests(string arg)
{
	string *sloved;
	int i,size_quest;
	object me;

	me = this_player();
	if( !this_guild->is_guild_member(me) )
		return notify_fail("很抱歉，这里并没有你的资料，请回到自己的公会查询。\n");

	sloved = me->query_finish_quests();
	if( !sloved || !( size_quest=sizeof(sloved) ) )
		write(set_color("你目前尚未完成任何的任务, 加点油吧!\n", "HIR"));
	else {
		for( i=0; i<size_quest; i++ )
			printf("你完成了 "+set_color("%s", "HIG")+
				   " 的任务。\n", to_chinese( sloved[i] ) );
		printf( "共得到 %3d 点的任务点数。\n" ,(int)me->query_quest_points());
	}
    return 1;
}

int do_help(string arg)
{

	switch(arg) {
		case "guild": write( @C_USAGE_GUILD
在这里你可以使用以下的指令，每一个指令都有更详尽的说明( 请用 "help <指令>" ):

  list        - 列出在这里你所能接受训练的技能项目。
  cost        - 列出升级、提升属性、或训练技能所需的经验值。
  advance     - 提升等级, 公会等级或属性。
  train       - 训练技能。
  join        - 加入这个公会，你的等级必须小於 5 级才能加入公会。
  verify      - 确认身分，或取回遗失的公会信物。
  explore     - 查寻你目前的冒险度。
  quests      - 列出你完成的所有任务。

C_USAGE_GUILD
			); break;
		case "list": write( @USAGE_LIST
指令格式: list

    这个指令能列出在这里你所能接受训练的技能项目。
USAGE_LIST
			); break;
		case "cost": write( @USAGE_COST
指令格式: cost

    这个指令能显示升级、提升属性、或训练技能所需的经验值。
USAGE_COST
			); break;
		case "advance" : write( @USAGE_ADVANCE
指令格式: advance [ str | int | dex | con | pie | kar | level | wizard ]

    当你的经验值足够时，这个指令能提升你的等级、公会等级、或属性。可是，
如果你的探险度及任务点数未达标准时，即使经验值足够亦不能升级。
USAGE_ADVANCE
			); break;
		case "train": write( @USAGE_TRAIN
指令格式: train <技能>

    当你拥有足够的经验值时，这个指令能提升你的技能。
USAGE_TRAIN
			); break;
		case "join": write( @USAGE_JOIN
指令格式: join

    这个指令能让你加入这个公会。另外要注意的是：某些公会加入前，或许会要
求具备某些特定条件；可以输入指令「info」来得到有关这个公会的一些资讯。
USAGE_JOIN
			); break;
		case "info": write( @USAGE_INFO
指令格式: info [<主题>]

    这个指令能给你一些有关这个公会有用的资讯，所以在你决定加入一个公会前
，一定要先阅读这些资讯。若在指令「info」後面没有指定主题的话，会给你一张
所有主题的列表。
USAGE_INFO
			); break;
        case "explore": write( @USAGE_EXPLORE
指令格式: explore

    这个指令能查寻你目前的冒险度。
USAGE_EXPLORE
			); break;
        case "quests": write( @USAGE_QUESTS
指令格式: quests

    这个指令能列出你已完成的所有任务。
USAGE_QUESTS
			); break;
		default:
			return 0;
	}
	return 1;
}
