#include "../hawk.h"
inherit MONSTER;
int times,jump;

void create ()
{
        ::create();
        set_level(15);
        set_name("Hawkman Magician","鸟人族魔法师");
        add("id",({"mage","hawkman","magician"}) );
        set_short("鸟人族魔法师");
        set_long(@C_LONG
鸟人原本不擅长魔法，但在大主教　裘拉根的训练之下也慢慢的有些鸟
人逐渐懂得魔法的使用。
C_LONG
        );
        set("alignment",-1000);
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "位" );
        set_perm_stat( "dex",15);
        set_perm_stat( "int",30);
        set_perm_stat( "karma",21);
        set("max_hp",500);
        set("max_sp",450);
        set("hit_points",500);
        set("spell_points",450);
        set_natural_weapon(22,10,20);
        set_natural_armor(35,15);
        set( "tactic_func","my_tactic");
        set("aim_difficulty",(["critical":30, "vascular":30]) );
        set("special_defense", (["all":50,"none":30]) );
        set_skill("dodge",70);
        set("spells/fireball",4);
        set("spells/lightning",2);
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set_skill("elemental",100);
        set("guild_levels/black-magic",40) ;
        set("guild_levels/elemental",40);
        set("guild_levels/guild",40);
	equip_armor( ARMOR"magerobe");
}

int my_tactic()
{
        int i;
        object victim;
        string name;
        if ( !(victim = query_attacker()) ) return 0;
        if (random(10) < 2) return 0;
//        if ((int)this_object()->query("spell_points")<1000)
//                this_object()->set("spell_points",3800);

        name=(string)victim->query("name");
        i=random(3);
        switch (i)
        {
                case 0:
                        command("cast fireball on "+name);
                        break;
                case 1:
                        command("tell "+name+" 你是赢不了的，不必再挣扎了。");
                        break;
                case 2:
                        command("cast lightning on "+name);
                        break;
                default :
                        command("say 有虫虫:~~\n");
                        break;
        }

    return 1;
}



