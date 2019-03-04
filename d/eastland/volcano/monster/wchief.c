#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(18);
	set_name( "Basge", "��˹��" );
	add( "id", ({ "basge" }) );
	set_short( "���������� ��˹��" );
	set_long(
	 "������˹���ǰ������е�ǿ�ߣ��㿴��ȫ�����ʵ����������˾����Ƶģ�˫��\n��������̫��Ѩ΢΢¡��ȫ����װ������ִ��һֻȨ�ȣ��о��������ϣ�Ϊ��\n������������������Ҳ�������ǡ�\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -900 );
	set_perm_stat( "str", 30 );
        set_perm_stat( "int", 20 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "kar", 20 );
	set_skill( "blunt", 100 );
	set_skill( "parry", 100 );
        set_skill( "block", 100 );
	set_skill( "dodge", 100 );
        set( "aim_difficulty",([ "critical":80,"weakest":80,"ganglion":80,"vascular":80 ]) );
	set( "wealth/gold", 80 );
        set( "hit_points", 750);
        set( "max_hp", 750);
        set("natural_armor_class",38);
        set("natural_defense_bonus",26);
        set_natural_weapon(8,5,15);
        ob1=new(OWEAPON"w_staff");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );
        equip_armor(OARMOR"mail5");
        equip_armor(OARMOR"legging1");
        equip_armor(OARMOR"shield1");
        equip_armor(OARMOR"armband2");
        equip_armor(OARMOR"helmet1");
        set("chat_chance",15);
        set("chat_output",({
          "����˵��Ϊ��ƽϢ����Ϊ�����˵İ�Σ����������ͷʵ���ǲ����ѵġ�\n",
        }) );
        set("inquiry", ([
            "volcano":"@@ask_volcano",
            "god":"@@ask_god",
            ]) );
}

void ask_volcano(object who)
{
  tell_object(who,
   "����˵��������ɽʵ�������ǵ�������������50��ǰ�ı��������������ļ��̴棬����\n�������������ǻ۵ĳ����Ѿ�����취�����������ˣ�ϣ�����ܾ����������\n"
  );
}

void ask_god(object who)
{
  tell_object(who,
   "����˵�����������У���Ҷ����Ż�ɽ��������Ϊ����ŭ�Ĺ�ϵ������������������ͷ\n�����������ÿ���ض������ӣ��ڻ�ɽ������ʦ����ƷͶ���ɽ֮�С�\n"
  );
}

int stop_attack()
{
	object slave, *tmp;

	slave = present( "wolf", environment() );
	if( !slave ) return 0;
	tell_room( environment(),
                "���ҹ����ҵ����ˣ���Ҫ���ˣ�\n" 
		"��˹��ĳ���--���� �������˹�����\n"
	);
	tmp = query_temp( "protectors" );
	if( !tmp || member_array( slave, tmp )==-1 ) {
		add_temp( "protectors", ({ slave }) );
		slave->add_temp( "protectees", ({ this_object() }) );
	}
	tmp = slave->query_attackers();
	if( !tmp || member_array( this_player(), tmp )==-1 )
		slave->kill_ob( this_player() );
}
