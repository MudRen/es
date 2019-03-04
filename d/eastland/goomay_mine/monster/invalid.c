#include <../zeus.h>
inherit MONSTER;

void create()
{
        ::create();
        set_level(7);
        set_name( "invalid", "病人" );
        add("id",({"invalid"}));
        set_short( "病人");
        set("unit","位");
        set_long( @LONG
这是一位全身包满绷带的人，躺在病床上有点无聊地看著天花板，也\许\他在
期待著有人来陪他讲讲话，他应该会告诉你他的伤(hurt)是怎麽来的
LONG
        );
        set_perm_stat("str",12 );
        set_natural_weapon(12, 6, 12);
        set_natural_armor( 40, 20 );
        set ("gender", "male");
        set ("race", "dwarf");
        set_c_verbs(({"%s用他的拐杖向%s打去","%s用他的脚向%s踢去","%s用他的拳头向%s攻击"}));
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon( ZOBJ"/stick" );

        set("inquiry",([
        "detonation":"@@ask_detonation", 
        "hurt": 
                "这身伤是在那次大爆炸中被烧伤的．\n"
      ]));
}
int ask_detonation()
{
tell_object(this_player(),
@AA
病人道：说起来也很莫名奇妙，那一天我刚好要送东西给工头，远远
地只瞧见工头不知道点燃了什麽东东，往身後一丢 (throw)结果轰一
声！醒来时就躺在这里了．
　　至於那东东，你可以四处找找，因为我也看到他也是随手拿来的
．希望你能找到真相！
AA
);
this_player()->set_temp("get/paper_torch",1);
}