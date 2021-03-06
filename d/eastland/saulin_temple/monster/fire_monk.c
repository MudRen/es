#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "fire monk", "火工头陀" );
        add ("id", ({ "monk" }) );
        set_short("火工头陀");
        set("unit","位");
        set_long(@C_LONG
你看到一位长的满脸横肉，叫人一看了就讨厌的人，他本来要投入少林当
和尚，可是因为品性不佳，没人肯帮他剃度，所以在少林作一些烧火打柴
的粗活，因为带发修行，所以他自称火工头陀。
看来他剃度修行是假，偷学武功\是真，他一定是偷经书(book)的人了。
C_LONG
        );
        set( "inquiry", ([
             "book" : "@@ask_book"  ]));

        set("alignment",-1200);
        set("wealth/silver",200);
        set_perm_stat("str", 20);
        set_perm_stat("dex", 22);
        set_skill("parry",80);
        set_skill("dodge",80);
	set_skill("unarmed",100);
        set_natural_weapon(20, 19, 25);
        set_natural_armor(70, 30);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 1800);
        set("force_points", 1800);
	set("force_effect",2);
        set("special_defense", ([ "all" : 25, "none" : 10 ]) );
        set("aim_difficulty", ([ "critical" : 20, "vascular" : 10,]) );
        set("gender", "male");
        set("race", "human");
        set_c_verbs(({ "%s施展大力金刚指向%s戳去", "%s用金刚掌拍向%s",
                       "%s用铁头功\一头向%s撞去" }));
}

void ask_book(object player)
{
    tell_object( this_player(), @ALONG
         火工头陀脸上一阵痉挛，邪笑道：
         你发现了老子的秘密，还想活著走出这里吗？
         
ALONG
                );
    kill_ob( player );
}

void die()
{
    object killer;

    if ( killer = query("last_attacker") ) {
    killer->set_temp("book_quest/step",2);
    tell_object(killer,@DIE
    
  「啊 ～～～ 我不要死，你饶了我吧!!」
  
火工头陀倒在地上口吐鲜血，眼见是不行了! 你突然心有不忍，
於是便替他急救，保住了他一命。

  「谢谢你 ! 但是我真的没有偷经书!! 我知道了狐狸的秘密以後，就常常
    来这里看书，但我从来不敢也没有必要把书带走，书真的不是我偷的!!」

你想想，一本在空中飘的书的确逃不过守卫的眼睛，於是你决定将火工头
陀绑在这里，然後去向方丈大师报告(report)详细的情形。

DIE
    );
    }
    call_out("remove",0);
}
