
#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "iron claws", "��צ");
        add ("id",({ "claws"}) );
        set_short( "��צ");
        set("unit", "��");
        set_long(
            "����һ�Կ���װ�����ϵ���צ����Ȼ�����������ۣ���������צ��ȴ���������Ĺ��\n"
        );
        set( "weapon_class", 10 );
        set( "type", "unarmed" );
        set( "min_damage", 8);
        set( "max_damage", 16);
	set("wield_func","wield_claws");
	set("unwield_func","unwield_claws");
        set( "weight", 55 );
	set("nosecond",1);
        set_c_verbs(({"%s����%s","%sץ��%s","%s����%s"}));
        set( "value", ({ 180, "silver" }) );
}

void unwield_claws()
{
	object owner;
	owner = environment(this_object());
 if (query("form"))
	{
        set( "weapon_class", 10 );
        set( "min_damage", 8);
        set( "max_damage", 16);
		set("prevent_drop",0);
        tell_room( environment(owner), 
        	owner->query("c_name")+"�Ļƽ�צ��â��ȥ�����ԭ�������ӡ�\n"
			, ({ owner }) );
        tell_object( owner, 
         "��Ļƽ�צ�����ȥ���Զ�������ַ��롣\n");

        set_name( "iron claws", "��צ");
        set_short( "��צ");
		set("form",0);
		return ;
	}
	return ;
}

void wield_claws()
{
	int st,iq,dx,kr,i,j;
	object owner;
	owner = environment(this_object());
	if ( (string)owner->query("class")=="adventurer")
	{
	st=owner->query_perm_stat("str");
        iq=owner->query_perm_stat("int");
        dx=owner->query_perm_stat("dex");
        kr=owner->query_perm_stat("kar");
	i = (st+dx+iq+kr)/3+random(6);
	j = ((int)owner->query_skill("unarmed"))/2 ;
        set( "weapon_class", ( j > 40 ? 40 : j ) );
        set( "min_damage", ( i<11 ? i : i-10 ));
        set( "max_damage", i);
	set("no_sale",1);
	set("prevent_drop",1);
        tell_room( environment(owner), 
         owner->query("c_name")+"����צ����һ���â���������ֽ�ϣ�����������һ���ݡ�\n"
	, ({ owner }) );
        tell_object( owner, 
	      "�����צ����һƬ��⣬�Զ�������ֽ��ܽ�ϡ�\n");
        set_name( "golden claws", "�ƽ�צ");
        set_short( "�ƽ�צ");
	set("form",1);
		return ;
	}
        return ;
}
