// armlance.c
//		��ħǹ
//
//		Lilia

#include <move.h>
#include "../lilia.h"

inherit WEAPON;

void create()
{
    seteuid(getuid());
    set_name("Magic Armored Lance", "��ħǹ");
    set_short("��ħǹ");
    add("id", ({"lance"}));
    set_long(@C_LONG
��˵��ħ��ĳ���սʿ��������ĵ���������ǹ���Ͽ���������������ΰ��
�����Ƕ���˹�����֣����������ǹ�����۴��κνǶ����ͣ�������������̾
�����ߵ���˼��
C_LONG
    );
    set("unit", "��");
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
	tell_object(p, "ֻ����ʿ����ʹ����ħǹ��\n");
	::unwield(0);
	return;
    }

    if (p->query_perm_stat("int") < 10)
    {
	tell_object(p, "���ǹ�Ĺ���̫���ӣ��㲻֪���ʹ������\n");
	::unwield(0);
	return;
    }

    if (wizardp(p) || p->query("npc"))
    { 
        if (p->query("armor/head") || p->query("armor/body") || p->query("armor/arms") || p->query("armor/hands") || p->query("armor/feet"))
        {
            tell_object(p, "�����ж������ħǹ��ͻ�Ļ��߲���װ����ħǹ��\n");
	    ::unwield(0);
	    return;
        }
    }
    else
    {
	if (p->query("armor/body"))
	{
	    tell_object(p, "�����ж������ħǹ��ͻ�Ļ��߲���װ����ħǹ��\n");
            ::unwield(0);
            return;
        }
    }

    if (p->query("weapon2"))
    {
	tell_object(p, "�����ж��������������װ����ħǹ��\n");
	::unwield(0);
        return;
    }

    tell_room(environment(p), set_color(sprintf("\n%s����ħǹ�߸߾��𣬴��һ��������������\n\n", p->query("c_name")), "HIY"), p);
    tell_object(p, set_color("\n�㽫��ħǹ�߸߾��𣬴��һ��������������\n\n", "HIY"));
    tell_object(p, set_color("��ħǹ��Ӧ������������û���һ�׿��ס�\n\n", "HIY"));

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
        leggings = new(ARM"shield");
        leggings->move(p);
        leggings->equip(1);
        tell_object(p, "��˳����������ħ�ܡ�\n");
	tell_room(environment(p), s+"˳����������ħ�ܡ�\n", p);
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

    tell_room(environment(p), set_color("��ħǹ�û���һ�׿��ף�˳���ش���"+p->query("c_name")+"������!\n", "HIY"), p);
    set("prevent_drop", 1);
    set("wielded", 1);
    p->calc_weapon_class();
}

void unwield(int silent)
{
    object p, helm, plate, arms, leggings, hands, feet;

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

