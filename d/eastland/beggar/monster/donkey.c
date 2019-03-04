#include "../dony.h"
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(16);
        set_name( "donkey", "大笨驴" );
        add( "id", ({ "donkey" }) );
        set_short( "大笨驴" );
        set_long(@C_LONG
这是一头年纪蛮大的大笨驴。它的一支眼睛已经瞎掉了,嘴巴里面也只剩下几颗稀
稀疏疏的牙齿, 走起路来摇摇摆摆尾巴一甩一甩的,吓!尾巴还会卷三个弯儿呢!如
果你不怕难为情,还可以骑著 ( mount ) 它到处去看看,不过小心它看到美女可会
『蹄蹄蹄』的叫著呢。 
C_LONG
        );        
        set( "unit", "匹" );
        set( "race", "monster");
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",60);
        set( "alignment", 0 );
        set( "extra_look","$N正骑著一头大笨驴上，看起来好糗喔。\n");
        set( "mountable", 1);
        set( "max_load", 2500 );
        set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
        set_c_verbs( ({ "%s抬起後腿, 往%s一踢", 
                        "%s的尾巴往%s一卷",
                        "%s用牙齿往%s一咬"}) );
        equip_armor(DARMOR"saddle");
}
void relay_message(string class, string msg)
{
  
     string who, str;
     object player;
          
     ::relay_message(class, msg);
     if( sscanf( msg, "%s(%s)走了过来。", str,who )==2 ) {
        if( !player = find_player(lower_case(who)) ) return;
        if( (string)player->query("gender")=="female"){  
            tell_object(player,
               "大笨驴用色色的眼光盯著你瞧,发出『蹄蹄蹄』的叫声!!\n");                 
            tell_room(environment(this_object()),
               "大笨驴发出『蹄蹄蹄』叫声,你往四周一看,哇!原来是有"+
               player->query("c_name")+"这个美女走了过来!!\n",player);
        }
     }
}
void init()
{
    mount::init();
}
