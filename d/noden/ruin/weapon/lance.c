// armlance.c
//		铠魔枪
//
//		Lilia

#include <move.h>
#include "../lilia.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
    set_name("Magic Armored Lance", "铠魔枪");
    set_short("铠魔枪");
    add("id", ({"lance"}));
    set_long(@C_LONG
传说中魔族的超级战士贝拉里尔的得意武器，枪柄上刻著铸造这把神兵的伟大
工匠亚尔罗斯的名字，这把美丽的枪，无论从任何角度欣赏，都令人由衷赞叹
铸造者的巧思。
C_LONG
    );
    set("unit", "把");
    set("no_sale", 1);
    set("weapon_class", 35);
    set("type", "jousting");
    set("min_damage", 20);
    set("max_damage", 40);
    set("weight", 250);
    set("no_second", 1);
}

void wield(int silent)
{
    object p, helm, plate, arms, hands, leggings, feet;
    string s;
    p = environment(this_object());
    s = p->query("c_name");

    if( query("wielded") ) return;
    if( !p || !living(p) ) return;
    if( userp(p) && this_object()->stop_wield(p) ) return;

    if (p->query("class") != "knight" && !wizardp(p))
    {
	tell_object(p, "只有骑士才能使用铠魔枪。\n");
	::unwield(0);
	return;
    }

    if (p->query_perm_stat("int") < 10)
    {
	tell_object(p, "这把枪的构造太复杂，你不知如何使用它。\n");
	::unwield(0);
	return;
    }

    if (wizardp(p) || p->query("npc"))
    { 
        if (p->query("armor/head") || p->query("armor/body") || p->query("armor/arms") || p->query("armor/hands") || p->query("armor/feet"))
        {
            tell_object(p, "你必须卸下与铠魔枪冲突的护具才能装备铠魔枪。\n");
	    ::unwield(0);
	    return;
        }
    }
    else
    {
	if (p->query("armor/body"))
	{
	    tell_object(p, "你必须卸下与铠魔枪冲突的护具才能装备铠魔枪。\n");
            ::unwield(0);
            return;
        }
    }

    if (p->query("weapon2"))
    {
	tell_object(p, "你必须卸下所有武器才能装备铠魔枪。\n");
	::unwield(0);
        return;
    }

    tell_room(environment(p), set_color(sprintf("\n%s将铠魔枪高高举起，大喝一声：「铠化！」\n\n", p->query("c_name")), "HIY"), p);
    tell_object(p, set_color("\n你将铠魔枪高高举起，大喝一声：「铠化！」\n\n", "HIY"));
    tell_object(p, set_color("铠魔枪呼应著你的勇气，幻化出一套盔甲。\n\n", "HIY"));

    plate = new(ARM"plate");
    plate->move(p);
    plate->equip(1);
    tell_object(p, "你顺利地穿上铠魔甲。\n");
    tell_room(environment(p), s+"顺利地穿上铠魔甲。\n", p);
    p->calc_armor_class();

    if (wizardp(p) || p->query("npc"))
    {
        helm = new(ARM"helm");
        helm->move(p);
        helm->equip(1);
        tell_object(p, "你顺利地戴上铠魔盔。\n");
	tell_room(environment(p), s+"顺利地戴上铠魔盔。\n", p);
        p->calc_armor_class();
        arms = new(ARM"arms");
        arms->move(p);
        arms->equip(1);
        tell_object(p, "你顺利地戴上铠魔臂。\n");
	tell_room(environment(p), s+"顺利地戴上铠魔臂。\n", p);
        p->calc_armor_class();
        leggings = new(ARM"shield");
        leggings->move(p);
        leggings->equip(1);
        tell_object(p, "你顺利地拿起铠魔盾。\n");
	tell_room(environment(p), s+"顺利地拿起铠魔盾。\n", p);
        p->calc_armor_class();
        hands = new(ARM"hands");
        hands->move(p);
        hands->equip(1);
        tell_object(p, "你顺利地戴上铠魔手。\n");
	tell_room(environment(p), s+"顺利地戴上铠魔手。\n", p);
        p->calc_armor_class();
        feet = new(ARM"feet");
        feet->move(p);
        feet->equip(1);
        tell_object(p, "你顺利地穿上铠魔鞋。\n");
	tell_room(environment(p), s+"顺利地穿上铠魔鞋。\n", p);
        p->calc_armor_class();
    }

    tell_room(environment(p), set_color("铠魔枪幻化出一套盔甲，顺利地穿在"+p->query("c_name")+"的身上!\n", "HIY"), p);
    set("prevent_drop", 1);
    set("wielded", 1);
    p->calc_weapon_class();
}

void unwield(int silent)
{
    object p, helm, plate, arms, leggings, hands, feet;

    p = environment(this_object());

    // quit 或装备被吃掉 (如大国师)
    if (p->query("armor/body"))
    {
    	plate = p->query("armor/body");
	plate->remove();
    }

    if (wizardp(p) || p->query("npc"))
    {
	if (p->query("armor/head"))
	{
     	    helm = p->query("armor/head");
	    helm->remove();
	}
	if (p->query("armor/arms"))
        {
            arms = p->query("armor/arms");
            arms->remove();
        }
	if (p->query("armor/feet"))
        {
            feet = p->query("armor/feet");
            feet->remove();
        }
	if (p->query("armor/shield"))
        {
            leggings = p->query("armor/shield");
            leggings->remove();
        }
	if (p->query("armor/hands"))
        {
            hands = p->query("armor/hands");
            hands->remove();
        }
    }

    set("prevent_drop", 0);

    ::unwield(0);
}

