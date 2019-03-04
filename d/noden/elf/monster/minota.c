#include "../layuter.h"

inherit MONSTER;

void create ()
{
        ::create();
        set_level(19);
        set_name( "minotaur", "ţͷ��" );
        add ("id", ({ "minotaur", "minota" }) );
        set_short( "ţͷ��" );
        set("unit","ֻ");
        set_long(
           " ��һ�־�ס��Թ���ص׵�ţͷ��������������ʮ�־޴�\n"
           " ���Ҳ����ƣ�����ò�Ҫ������\n"
        );
        set("killer",1);
        set("alignment",-1000);
        set("wealth/gold",600);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 22);
        set_perm_stat("int",15);
        set_perm_stat("kar",25);
        set_perm_stat("pie",10);
        set("max_hp",700);
        set("hit_points",700);   
        set_natural_weapon( 28, 15, 18 );
        set_natural_armor( 93, 40 );
        set ("gender", "male");
        set_c_verbs(({"��%s��%s��ȥ","��%sʹ����ɱһ����%s����"}));
        set_c_limbs(({"����","ͷ��","�Ų�","�ֱ�","�ز�"}));
        set_skill("parry",90);
        set_skill("dodge",60);
        set_skill("axe",100);
        wield_weapon(LWEAPON"axe");        
}

void die()
{
	object killer;
	
	killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#33");
	::die();
}
