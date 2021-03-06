#include <../hole.h>

inherit REPORT ;
inherit ENEMY ;
void create ()
{
        ::create();
        set_level(19);
        set_name( "Lizardman Leader Bulansido","布伦希多" );
        add ( "id",({ "lizardman","leader","bulansido" }) );
        set_short( "蜥蜴人首领 布伦希多" );
        set_long(@LONG
    你看到的是一只巨大的蜥蜴人，它的身长将近三公尺，光是它的
尾巴就有二公尺，可别以为它的尾巴只是装饰用的，它的尾巴可说是
相当可怕的武器喔。它是目前蜥蜴人村落中的领袖，统领著这个地下王
国，当年它打倒所有王位挑战者，以全胜的战绩登上王位，所以它的
外号又称为『战神』。
LONG
		);
        set( "unit","位" );
        set( "exp_reward",45000 );
        set( "alignment",3000 );
        set( "wealth/silver",1000 );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "weight",200 );
        set( "max_hp",2000 );
        set( "hit_points",2000 );
        set( "tactic","assault" );
        set( "unbleeding",1 );
        set( "special_defense",([ "all":70,"none":80 ]));
        set( "tactic_func","tail_attack" );
        set_c_limbs(({ "头部","胸口","手臂","腹部","尾巴" }) );
        set_perm_stat( "int",15 );
        set_perm_stat( "str",30 );
        set_perm_stat( "dex",30 );
        set_perm_stat( "kar",30 );
        set_perm_stat( "pie",20 );
        set_perm_stat( "con",30 );
        set_natural_weapon( 40,18,35 );
        set_natural_armor( 50,29 );
        set_skill( "dodge",100 );
        set_skill( "longblade",100 );
        set_skill( "parry",100 );
        set_skill( "block",100 );
        set_skill( "tactic",100 );
        wield_weapon( HWEAPON"king_sword" );
        equip_armor( HARMOR"shield2" );
        equip_armor( HARMOR"arms1" );
        equip_armor( HARMOR"cloak1" );
        equip_armor( HARMOR"plate2" );
        equip_armor( HARMOR"helmet1" );
        set( "inquiry",([
        		"halberd" : "@@ask_halberd",
        		"valor" : "@@ask_valor",
        		]) );
}

void init()
{
	::init();
	add_action( "to_report","report" );
	add_action( "to_embattle","embattle" );
	add_action( "to_demand","demand" );
}

int to_embattle()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"布伦希多狠狠的瞪了"+c_him+"一眼说道：围攻我？想都别想，单挑吧。\n",player );
	tell_object( player,"布伦希多狠狠的瞪了你一眼说道：围攻我？想都别想，单挑吧。\n" );
	command( "kill "+him );
	return 1;
}

int to_demand()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"布伦希多狠狠的瞪了"+c_him+"一眼说道：找帮手？想都别想，乖乖单挑吧。\n",player );
	tell_object( player,"布伦希多狠狠的瞪了你一眼说道：找帮手？想都别想，乖乖单挑吧。\n" );
	command( "kill "+him );
	return 1;
}

int tail_attack()
{
    object env,*victim;
    int i;
    env=environment(this_object());
    victim=query_attackers();
    if(!victim) return 0;
    if( random(99)>19 ) return 0;
    tell_room( env,"\n蜥蜴人首领 布伦希多 用它巨大的尾巴扫向在场所有敌人。\n");
    i=sizeof(victim);
    while(i--)
    {
     if (victim[i]!=this_object())
        {
	 victim[i]->receive_damage(75);
	 report( victim[i] );
        }
    }
    return 1;
}

void ask_halberd()
{
	tell_object( this_player(),@HALBERD

布伦希多说道：
关於这件世间罕见的神兵利器我也没见过。

HALBERD
		);
		return;
}

void ask_valor()
{
	object player;
	
	player=this_player();
	if( player->query_temp("lizard_quest/leader") ){
	tell_object( player,@VALOR

布伦希多说道：
既然你是勇士的朋友，那我就告诉你吧！最近几个月来，村子里发生
一连串的死亡事件，广场东北边岗哨的卫兵常常被摸掉，本来大家都
认定是武士堡忍者的杰作，但经过拉索达的验尸判断，死者都是被吸
乾血液而死，因此我们都认为，可能有怪物栖息在村子的某个角落。
不过我们并不确定怪物的栖息地，也不知道如何才能消灭它。为了防
止更多人莫名的丧失性命，我已经下令将岗哨往後彻。如果你想帮我
调查，我建议你先去旧岗哨找找看有无蛛丝马迹。如果有任何新发现
，记得来告诉我。

VALOR
		);
	player->delete_temp("lizard_quest/leader");
	return ;
	}
	tell_object( player,"布伦希多用怀疑的眼光看著你。\n" );
	return;
}

int to_report(string arg)
{
	string what,man;
	
	if( !arg || sscanf(arg,"%s to %s",what,man)!=2 )
		return notify_fail( "布伦希多说道：『嗯？你有什麽新发现吗？』\n" );
	if( man!="blansido" && man!="leader" )
		return notify_fail( "这里没有这个人。\n" );
	if( what!="vampire" )
		return notify_fail( "你确定吗？我想，你还是再去勘查看看。\n" );
	else
	{
	tell_object( this_player(),@VAMPIRE

布伦希多说道：
原来作怪的是吸血鬼，不过吸血鬼是很难对付的一种不死族怪物，想
消灭它可能需要用到魔法，可是我们蜥蜴一族却没有人有这方面的知
识。我想，你可以去问问拉索达，或许她知道该如何消灭吸血鬼。

VAMPIRE
		);
	this_player()->set_temp("lizard_quest/poutiff",1);
	return 1;
	}
}
