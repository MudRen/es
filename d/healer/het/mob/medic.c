#include <mudlib.h>
#include <conditions.h>
#include "../wang.h"
inherit MONSTER;
inherit TEACHER;

void create()
{
	object ob1;
	::create();
	set_level(19);
	set_name( "Medic Wang", "王药师" );
	add( "id", ({ "medic", "wang" }) );
	set_short("王药师" );
	set_long(
@LONG
王药师原本是行医者公会的一员，他是行医者公认的草药权威，几乎所有珍
贵药草生长的地点都是他发现的。几年前突然离开公会，来到这地方隐居。
此後每天不是出去采药就是调制各种奇怪的药，没有人知道他想做什麽。
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat("str",30);
	set_perm_stat( "int", 30 );
	set_perm_stat( "kar", 25 );
	set_perm_stat( "dex", 30 );
	set_skill( "dodge", 100 );
	set_skill( "blunt", 100 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "weakest" );
	set( "max_hp", 600 );
	set( "force_point", 100 );
	set( "hit_points", 600 );
	set_natural_armor( 100, 50 );
	set_natural_weapon( 30, 15, 25 );
	set( "special_defense", ([ "all": 50,"none":60]) );
	set( "aim_difficulty",([ "weakest":30,"vascular":20 ]) );
	set( "alignment", 500 );
        set( "inquiry", ([
		"poison" : "@@ask_poison",
		"herb" : "@@ask_poison",
		"train" : "@@ask_train",
		])
	);	
        set( "chat_chance", 2 );
        set( "chat_output", ({
                "王药师喃喃地念著:「无根水三两.. 付子五钱... 」\n",
                "王药师站起来, 走出房间, 过一会儿拿了些药草进来，开始调配。\n",
        }) );

	set_lessons( ([
		"venomlogy" : ({ 150,90 })
	]));

	set( "tactic_func", "my_tactic" );
	wield_weapon( MY_WEAPON );
	equip_armor( ITEM"deer_gloves.c" );
	ob1 = new(ITEM"box.c");
	ob1->move(this_object());

}

void init()
{
	teacher::init();
}

//
// msgs[random(sizeof(msgs))]
// but 这段常常被 call when fighting , 还是先算出来 size 多大比较好
//
int my_tactic()
{
	string *msgs = ({"\n王药师从药囊中抓出一把毒沙，往%s撒去!\n\n",
			 "\n王药师袖中喷出一道黄色的水，喷的%s满身都是!\n\n",
			 "\n王药师的指甲中突然弹出一道青色的烟，直冲%s...\n\n",
			 ""});
	string msg1 = "王药师哈哈大笑说道：「竟敢在用毒的祖宗前卖弄，你不知道这叫班门弄斧吗?」\n 王药师取出药丸服下，竟自行解毒了。\n"; 
	object me,victim,env;
	int type;
	string msg;

	me = this_object();
	env = environment( me );
	if ( me->query("conditions/weak") ) {
		tell_room(env,msg1);
        	me->modify_stat("str",(int) me->query("weak"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}
	if ( me->query("conditions/slow") ) {
		tell_room(env,msg1);
        	me->modify_stat("dex",(int) me->query("slow"));
        	(CONDITION_PREFIX + "weak")->remove_effect(me);
	}

	if ( ( me->query("conditions/simple_poison")) ) {
		tell_room(env,msg1);
		(CONDITION_PREFIX + "simple_poison")->remove_effect(me);
	}

//      机率

	victim = query_attacker();
	if ( random( 10 + victim->query_perm_stat("kar") ) > 14 )
		return 0;

	msg = sprintf( msgs[ (type = random(3)) ], victim->query("c_name") );
	tell_object(victim,
              "\n王药师双手一挥，大笑道 ： 「哈哈 !! 来得好 !! 正好来让我试试药 !!」 \n" );
	tell_room(env,msg,victim);
	switch(type) {
		case 0:
        		(CONDITION_PREFIX + "simple_poison") ->
                		apply_effect(victim,12,6);
			break;
		case 1:
        		(CONDITION_PREFIX + "weak") ->
                		apply_effect(victim,12,6);
			break;
		case 2:
        		(CONDITION_PREFIX + "slow") ->
                		apply_effect(victim,12,6);
			break;
		default:
			break;
	}
	return 0;	
}

void ask_poison(object visitor)
{

	if( (string) visitor->query("class") != "healer" ) {
	 	tell_object(visitor,"你不是医生，我想你是不懂得药性的人，还是算了吧\n") ;

	}  else {
		     tell_object(visitor,
"熟悉毒药并不一定是坏事，如果用对地方..。我离开行医者公会一段时间了,\n"
"这一段时间内，搜集了一些配方，另外还有自己发现的。\n"
"如果你有兴趣，我可以教你毒物学。如果下毒的技巧不够好，你自己有可能中毒的。\n"
"药方在後面房间，你去看看吧。\n"
			);
	}
}

void ask_train(object who)
{
	if ( (string) who->query("class") == "healer" ) {
		tell_object( who ,
"想跟我学毒物学(venomlogy)吗? 你找对人了。我正好缺些解毒用的药材，\n"
"如果你能带一些给我,我很乐意教你的。\n");
	} else
		tell_object( who,
"很抱歉, 我只教行医者, 你另请高明吧。\n");
		
}

// not finished ..
int check_trainee(object trainee)
{
	if ( (string) trainee->query("class") != "healer" ) {
		tell_object(trainee,"很抱歉, 这项技能我只传授给行医者。\n");
		return 0;
	}
	if (! (trainee->query_temp("give_herb/herb1")  && 
	     trainee->query_temp("give_herb/herb2")) ) {
		tell_object(trainee,"请你再拿些药材给我吧。\n") ;
		return 0;
	}
	return 1;
}

int accept_item(object who, object item)
{
	if ( (string) item->query("ident") == "SWAMP_BERRY" ) {
		tell_object( who, "谢谢你，我正需要这味药材。\n") ;
		who->set_temp("give_herb/herb1",1);
		item->remove();
	} else if ( (string) item->query("ident") == "SWAMP_MOSS") {
		tell_object( who, "谢谢你，我正需要这味药材。\n") ;
		who->set_temp("give_herb/herb2",1);
		item->remove();
	} else if ( item->query("ident") ) {
		tell_object( who,"虽然我不需要这味药, 还是谢谢你。\n");
		item->remove();
	}
	return 1;
}

void die()
{
	object killer,env,*inv;
	int i;
	env = environment( this_object() );
        inv = all_inventory( env );
	killer = query("last_attacker");
	if ( ! killer || ! env || !inv ) {
		::die();
		return;
	}

        i = sizeof(inv);
	tell_room(env,"王药师说道:「你.. 你们会後悔的....」\n",this_object());
        while(i--) {
		if ( living(inv[i]) && ! inv[i]->query("npc") )
                	inv[i]->set_temp("kill_wang",1);
        }
     	::die();
}

