#include "../iigima.h"

inherit ARMOR;

void create()
{
        set_name("Lucky plate","幸运铠甲");
        add("id",({"plate"}) );
         set_short( "幸运铠甲");
	set_long(@C_LONG
这是一件有刻有小刀图纹的轻质铠甲□黝黑而不能反光
的特性证明了这是属於某些在黑夜中活动的人的装备，
由於质地相当轻巧，你忍不住想穿看看。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 145 );
	set( "type", "body" );
	set( "material", "thief");
	set( "armor_class", 18 );
        set( "defense_bonus",0 );
	set( "value", ({ 330, "gold" }) );
        set( "equip_func","wield_plate" );
        set( "unequip_func","unwield_plate" );        
}

void wield_plate()
{
        string cla,him,bonus;
        object player,env;
        player=this_player();
        env=environment(player);
        him=player->query( "c_name" );
        cla=player->query( "class" );
         if( cla!="thief" ) {
                tell_object(player,"\n一股邪气自铠甲内发出，令你浑身不愉快。\n\n");
 tell_room(env,"\n\n你看到"+him+"古怪地皱了眉头，扭动身体好像长了痔疮....\n\n");
 }
        else{
tell_room(env,
   "\n\n你看见"+him+"穿上幸运铠甲後，快乐的自顾自个儿跳著舞，好像有点秀斗..\n\n",player);         
tell_object(player,
"\n\n忽然一股勇气与愉快的感觉自你内心发出，令你不禁手足舞蹈一番\n\n");
                set( "armor_class",30 );
                set("defense_bonus","@@lucky_bonus");
         return ;
        }
        return ;
}
void unwield_plate()
{
        set( "armor_class",18 );
        delete( "defense_bonus" );
        return ;
}
int lucky_bonus()
{ 
   return 4 + random(4);
}     
