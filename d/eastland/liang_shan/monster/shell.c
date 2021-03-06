#include "../takeda.h"
#include "/include/move.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "shell", "千年老蚌" );
        add ("id", ({ "shell" }) );
        set_short( "千年老蚌");
        set("unit","个");
        set_long(
           "    你看到一个非常巨大的蚌，粗糙的外壳就如同石头般坚硬，表面长满\n"
           "了许\多水生藻类，使你看不清原来的纹路，在两片蚌壳的接缝处，隐隐透\n"
           "出一股淡淡的宝光。\n"
        );
        set( "likefish",1);
        set( "unbleeding",1);
        set( "max_hp",700 );
        set( "hit_points",500 );
        set("alignment",200);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 25);
        set_perm_stat("kar",27);
        set_natural_weapon( 50, 30, 50 );
        set_natural_armor( 150, 65 );
        set ("gender", "male");
        set ("race", "monster");
        set_c_limbs(({"硬壳"}));
        set_c_verbs( ({"%s卷动整个湖水，一片漩涡猛然袭向%s","%s怪呜数声，一束极速沙石轰然砸向%s","%s打开蚌壳，一道寒光并出，射向%s","%s用硬壳紧紧夹住%s","%s用水管喷出一股强劲水流，打向%s"}));
}

void die()
{  
   object ob1,killer;
   
   ob1 = new(TOBJ"pearl");
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   tell_room(environment(this_object()),
      "\n你的最後一击打破了这个坚硬的蚌壳，使你能够看清楚蚌壳的内部\n\n\n\n"
      "你在蚌壳内发现到一个相当罕见的美丽珠子，正发出美丽的光芒，你看\n"
      "的合不拢嘴，马上伸手进去把珠子掏出来。\n",
      this_object());
   if( (int)(ob1->move(killer)) != MOVE_OK )
		ob1->move(environment(this_object()));  
   ::die();   
}
