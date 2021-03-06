#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "@@name","『诸神的黄昏』" );
         add("id",({"sword","ragnarok"}));
	set_short( "@@short" );
	set_long(@LONG
这把黝黑的长剑的剑柄上缠绕了八条石蛇像，有如藤蔓紧紧围绕
著，剑舌上的蓝色蛇眼半遮半掩，隐隐透露著青光，似乎隐藏著
不可知的力量。
LONG
		);
	set( "unit","把" );
   set( "type", "longblade" );
   set( "weapon_class",40 );
   set( "min_damage", 16 );
   set( "max_damage", 33 );
	set( "weight",165 );
        set( "no_sale",1);
        set( "wield_func", "body_look" );
	set( "value",({ 9600,"silver" }) );        
	set( "hit_func","thunder_damage" );
}

string name(){ return set_color ("Ragnarok","HIY");}
string short(){ return set_color ("『诸神的黄昏』","HIY"); }

int thunder_damage(object victim,int damage)
{
	object holder;
   int dam, max, mysp, mytp, mykar, tarkar;
	string msg1,msg2,him,me;

   dam = environment(this_object())->query_stat("str");
   mysp = environment(this_object())->query("spell_points");
   mytp = environment(this_object())->query("talk_points");
	if ( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   if( mysp < 21 || mytp < 42 ) return 0;
   if ( (int)holder->query_skill( "longblade" )<100 )
	{
	tell_object( holder,"\n『诸神的黄昏』的封印之眼发出一阵青光刺痛你的双眼。\n" );
   holder->receive_damage( dam );
	victim->set( "last_attacker",holder );
        return 0;
	}
	else
	{
	mykar = environment(this_object())->query_stat("kar");
        tarkar = victim->query_stat("kar");
        max = mykar - tarkar;
	if( max < 0 ) max = 0;
        if( random(mykar) < 9 ) return 0;
	him=victim->query( "c_name" );
	me=holder->query( "c_name" );
	tell_object( holder,set_color("\n『诸神的黄昏』的封印之眼忽然张开，召唤一道天雷劈向"+him+"！！\n\n","HIB") );
	tell_object( victim,
"\n"+me+"召唤一道天雷打中你的头顶，你被打的眼冒金星，全身疼痛。\n\n" );
	tell_room( environment(holder),"\n忽然一阵巨响！！『诸神的黄昏』召唤天雷将"+him+"劈成焦炭！！\n\n",({ holder,victim }) );
   holder->add( "spell_points", -max-2 );
   holder->add( "talk_points", -max*2-4 );
   victim->receive_special_damage( "divine", dam+max );
	victim->set( "last_attacker",holder );
   return dam+max;
   }
}

void body_look()
{
 object holder;

 holder = environment(this_object());
 tell_object( holder,set_color(
    "\n石像眼中发出光芒，八条蛇迅速活动，卷曲地缠绕住你的手腕！\n\n","HIB"));
   set("extra_look",set_color(
   "一只只石蛇弯曲的缠绕在$N的手腕上，不停地扭动著！！\n","HIG"));
}	

// 特殊攻击如下:
// 命中率约 1/3, 最大伤害 31(str) + 14 = 45
