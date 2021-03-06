#include <../goomay.h>

inherit MONSTER;

int is_iced = 0;

void create()
{
	::create();
	set_level(13);

        set_name( "@@query_short", "@@query_c_chort" );
        add( "id", ({ "beast","spirit" }) );
        set_short( "@@query_c_short" );
        set("long", "@@query_c_long");

	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "alignment", 500 );
	set( "natural_armor_class", 60 );
	set( "natural_defense_bonus", 20 );
	set( "natural_weapon_class1", 32 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"火妖怒吼道：「可恶 !! 你们制造了我，却又要杀我 !!」 \n",
		"火妖怒吼道：「让你尝尝我火焰的厉害 !! 」\n"
	}) );


}
string query_short()
{
	if ( !this_player() ) return "fire beast";
 if (this_player()->query_temp("fire_element"))
	return "fire spirit";
	return "fire beast";
}
string query_c_short()
{
	if ( !this_player() ) return "火妖" ;
 if (this_player()->query_temp("fire_element"))
        return "火精灵";
        return "火妖";
}

string query_c_long()
{
	if ( ! this_player()) return "";
 if (this_player()->query_temp("fire_element"))
    return "这只火精灵有著火红色的眼珠和头发，它的额头上有一个火焰的印记，当\n"
              "你的视线接触到他的眼睛时，它笑的很开心。\n";

return "这只火妖有著火红色的眼珠和头发，它的额头上有一个火焰的印记，当\n"
	"你的视线接触到他的眼睛时，发觉它比你想像的平和。\n";
}

int accept_item(object me,object item)
{
object ob,ob2;
     if ((string) item->query("name") !="crystal of ice" ) return 1;
     if (this_player()->query_temp("fire_element")) return 1;
     tell_object(me,
@MISSION
火妖呆呆的接过万年冰晶，脸上突然涌起一阵激动的笑容，它惊讶又
怀疑的看著你，在你始终如一的笑容下，两行泪\水滑过它火红的面颊
，它用颤抖的声音说道：「这世上从没有人了解过我们，我们不是邪
恶种族，在极端的环境下出生的我们需要的只是适切的关怀和满足，
这个冰晶正可以使我们脱去火性，转变成拥有平衡生命的妖精，谢谢
你的付出和了解，再见了 !! 我的朋友 !! 希望有一天还能再见到你」

火妖把冰晶放在它的胸口，突然强烈光华四射，你听到「答」的一声
轻响，好像有什麽东西落在地上，你睁开双眼一看，火妖已经不见踪
影了。
你的耳边响起一阵若有若无的声音一直重复著：西边.. 西边 ..
MISSION
         );

                item->remove();
                ob = new( Obj"fire_element" );
                ob->move( environment(this_object()) );

		this_player()->set_temp("fire_element",1);
                if ((string)this_player()->query("class")=="scholar") {
                   tell_object(this_player(),"火精灵的声音回汤在你耳边：需要帮忙的时後请CALL我，不要忘记我喔 !\n");
                   this_player()->set("demand/fire",2);
                }
                remove();
        return 1;
}

void report( object attacker, object victim )
{
   string c_message;
   seteuid(getuid());
   c_message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( 你"+c_message+" )\n");
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n火妖伸出一道火焰，扫过你的身体，你感到一阵灼烫 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
                "\n火妖散发出强烈的光芒，你的眼睛一阵刺痛 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
	{
	tell_object( victim[i], 
		"你的墨镜挡住了刺眼的强光。\n\n");
	}
	else
	{
        if( victim[i]->query("stop_attack") ) continue;
        victim[i]->block_attack(8);
        victim[i]->set_temp("msg_stop_attack", 
          "( 你现在什麽也看不到 ! )\n" );
	}
	}
	return 1;
	}
	return 0;
}

void iced()
{
	is_iced = 1;
	tell_room( environment(this_object()), 
	"火妖大声尖叫：「 该死的家伙 ! 把那个东西拿开 !」\n" ,
		this_object() );
}

void die()
{
	object ob;
	if( is_iced )
	{
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"火妖大叫一声，碎裂成许\多小火球 ....\n\n"
			"你听到一阵低沈的声音从火球中发出: 「你以为这样就结束了吗？」\n\n"
			"小火球又重新聚在一起，火妖又从火中重生。\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", Mob"fire_beast" );
		::die(1);
	}
}
