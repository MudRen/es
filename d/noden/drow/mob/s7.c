#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

 void create()
{
        ::create();
        set_level(18);
        set_name("mad snake","�ͱ�����");
        add("id",({"snake"})); 
        set_short("�ͱ�����");
	set_long(@C_LONG
�ͱ����ߣ�ͨ�������ߵĶ���һ��ҪԶԶ����½��
��һ�ٱ������ϣ�������¶���ĺ�������ˮ����
�����������Ļƣ�������������Ҫ˵�������ײ�
����ӵ�����������Ķ��ԡ�
C_LONG
        );
        set( "unit", "��" );
	set( "alignment", -1500 );
         set( "max_hp", 500 );
          set( "hit_points", 500 );
   set_perm_stat( "dex", 30 );
	set("likefish",1);
        set( "natural_weapon_class1", 46 );
        set( "natural_min_damage1", 24 );
        set( "natural_max_damage1", 38 );
        set( "tactic_func", "emit_poison" );
        set_c_limbs( ({ "ͷ��", "����������", "������β��" }) );
        set_c_verbs( ({ "%s�������ƣ���%s����ػ���ҧ��" }) );
   set( "killer", 1 );
}
int emit_poison()
{
        object victim;

        if( random(15)>6 || !(victim= query_attacker()) ) return 0;
        tell_room( environment(this_object()),
                "�ͱ����߻��ε�����ߣ����ŵ�ҧ���㣬һ�����鴫��\n", 
                this_object() );
        (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 
5, 36 );
        return 1;
}       
void die()
{   object obj,who;
    tell_room(environment(this_object()),
@DIE

�ͱ����߾���Ť�������з���һ���������˿����������Ѽ���!

DIE
,this_object());
   obj=new("/d/noden/drow/arm/lucky_bracers");
    obj->move(this_object());
   ::die(1);
   }


