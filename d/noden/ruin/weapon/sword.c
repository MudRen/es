// armsword.c
//		��ħ��
//
//		Lilia

#include <move.h>
#include "../lilia.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
    set_name("Magic Armored Sword", "��ħ��");
    set_short("��ħ��");
    add("id", ({"sword"}));
    set_long(@C_LONG
��˵��ħ��ĳ���սʿ�������ĵ����佣�������Ͽ���������������ΰ��
�����Ƕ���˹�����֣���������Ľ������۴��κνǶ����ͣ�������������̾
�����ߵ���˼��
C_LONG
    );
    set("unit", "��");
    set("no_sale", 1);
    set("weapon_class", 35);
    set("type", "longblade");
    set("min_damage", 20);
    set("max_damage", 40);
    set("weight", 250);
    set("second", 1);
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
	tell_object(p, "ֻ����ʿ����ʹ����ħ����\n");
	::unwield(0);
	return;
    }

    if (p->query("race") == "lizardman")
    {
        tell_object(p, "��ħ���������������������������еĿ־�ʹ���޷�ʹ������\n");
	::unwield(0);
	return;
    }

    if (p->query_perm_stat("int") < 10)
    {
	tell_object(p, "��ѽ��Ĺ���̫���ӣ��㲻֪���ʹ������\n");
	::unwield(0);
	return;
    }

    if (wizardp(p) || p->query("npc"))
    { 
        if (p->query("armor/head") || p->query("armor/body") || p->query("armor/arms") || p->query("armor/hands") || p->query("armor/legs") || p->query("armor/feet"))
        {
            tell_object(p, "�����ж������ħ����ͻ�Ļ��߲���װ����ħ����\n");
	    ::unwield(0);
	    return;
        }
    }
    else
    {
	if (p->query("armor/body"))
	{
	    tell_object(p, "�����ж������ħ����ͻ�Ļ��߲���װ����ħ����\n");
            ::unwield(0);
            return;
        }
    }

    tell_room(environment(p), set_color(sprintf("\n%s����ħ���߸߾��𣬴��һ��������������\n\n", p->query("c_name")), "HIY"), p);
    tell_object(p, set_color("\n�㽫��ħ���߸߾��𣬴��һ��������������\n\n", "HIY"));
    tell_object(p, set_color("��ħ����Ӧ������������û���һ�׿��ס�\n\n", "HIY"));

    plate = new(ARM"plate");
    plate->move(p);
    plate->equip(1);
    tell_object(p, "��˳���ش�����ħ�ס�\n");
    tell_room(environment(p), s+"˳���ش�����ħ�ס�\n", p);
    p->calc_armor_class();

    if (wizardp(p) || p->query("npc"))
    {
        helm = new(ARM"helm");
        helm->move(p);
        helm->equip(1);
        tell_object(p, "��˳���ش�����ħ����\n");
	tell_room(environment(p), s+"˳���ش�����ħ����\n", p);
        p->calc_armor_class();
        arms = new(ARM"arms");
        arms->move(p);
        arms->equip(1);
        tell_object(p, "��˳���ش�����ħ�ۡ�\n");
	tell_room(environment(p), s+"˳���ش�����ħ�ۡ�\n", p);
        p->calc_armor_class();
        leggings = new(ARM"leggings");
        leggings->move(p);
        leggings->equip(1);
        tell_object(p, "��˳���ش�����ħ�ɡ�\n");
	tell_room(environment(p), s+"˳���ش�����ħ�ɡ�\n", p);
        p->calc_armor_class();
        hands = new(ARM"hands");
        hands->move(p);
        hands->equip(1);
        tell_object(p, "��˳���ش�����ħ�֡�\n");
	tell_room(environment(p), s+"˳���ش�����ħ�֡�\n", p);
        p->calc_armor_class();
        feet = new(ARM"feet");
        feet->move(p);
        feet->equip(1);
        tell_object(p, "��˳���ش�����ħЬ��\n");
	tell_room(environment(p), s+"˳���ش�����ħЬ��\n", p);
        p->calc_armor_class();
    }

    tell_room(environment(p), set_color("��ħ���û���һ�׿��ף�˳���ش���"+p->query("c_name")+"������!\n", "HIY"), p);
    set("prevent_drop", 1);
    set("wielded", 1);
    p->calc_weapon_class();
}

void unwield(int silent)
{
    object p, firstwep, secondwep, helm, plate, arms, leggings, hands, feet;

    p = environment(this_object());

    // quit ��װ�����Ե� (����ʦ)
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
	if (p->query("armor/legs"))
        {
            leggings = p->query("armor/legs");
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

