#include <mudlib.h>

inherit WEAPON ;

void create()
{
        set_name("The seven-blade", "����ն");
        add ("id", ({"seven","blade","the seven blade" }) );
   set_short("����ն");
        set_long(
                "������һ�ɡ��ľ��С�����ն��\n"
        );
        set("type", "longblade");
        set("weapon_class",15);
        set("no_sale",1);
        set("no_second",1);
        set("min_damage", 5 );
        set("max_damage", 15);
        set("weight", 50);
        set("wield_func","wield_blade");
        set("value", ({ 10, "gold" }) );
	set_c_verbs( ({ 
		"%sһ���������ݰ�ת������Ȼһ�ƴ���%s",
		"%s�����Ķ��ǡ�һ��ʹ����ֻ��ɳ����ɣ�\nһʮ�����Ѵ���%s",
		"%s��������Х��������������������ʹ����\n����ն��%s",
	}) );
}
