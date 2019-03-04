// This is the combat controller daemon seperated from /std/body/attack.c
// Call report_combat to report an attack.
// By Annihilator 10/15/93

#include <daemons.h>
#include <martial.h>
#include <attack.h>

// The default database of verb messages

mapping c_dflt_verbs = ([
	"unarmed": ({
		"%s��׼%sһ��ֱȭ", "%s����%sһ��", "%s��ȭ����%s", "%s����ץ��%s" }),
	"longblade": ({
		"��%sб��%s", "��%s����%s", "%sһ�ӣ�ն��%s", "�Ӷ�%s����%s��ȥ" }),
	"shortblade": ({
		"��%sб��%s", "��%s����%s", "����%s��˳����%sһ��", "��%s��׼%s����ֱ�̳�" }),
	"dagger": ({
		"����%s����%s�ݺ�һ��", "����%s��˳����%sһ��", "��%s��׼%s����ֱ�̳�",
		"%s�׹�һ�����ӽ������ʹ�%s" }),
	"thrusting": ({
		"%s��׼%s������һ��", "�ع�%s��ֱֱ����%s", "%s����%s",
		"��%sб��%s" }),
	"blunt": ({
		"����%s����׼%s��ͷ����", "��%s��%s��ȥ", "��%s���ص���%s��ȥ", "��%sɨ��%s" }),
	"axe": ({
		"��%s��%s����", "����%s������%s", "��%s��׼%s����һ��", "��%s����һ������ն��%s",
		"�߾�%s����%s����" }),
	"polearm": ({
		"�Ӷ�%s����%sɨ��", "��%s��׼%s��ǰֱ��", "%sһ�ӣ�����%s", "˫�ֻ�����%s����%s��ɨ��ȥ" }),
	"wand": ({
		"����%s������%s", "��%s��%sһ��", "��%s��%sһ��", "��%sɨ��%s" }),
	"chain": ({
		"˦��%s������%s", "��%s��%s������ȥ", "��%sɨ��%s" }),
	"whip": ({
		"˦��%s������%s", "�趯%s��%sһɨ", "��%sֱֱ�ػ���%s" }),
	"jousting": ({
		"%s��׼%s������һ��", "��%sֱֱ����%s", "%s����%s",
		"��%sб��%s" }),
]);

// The default database of limb messages

string *c_dflt_limbs = ({
	"����", "���", "�ұ�", "ǰ��", "����", "����", "���", "�Ҽ�",
	"����", "С��" });

// These parameter are used by many functions and are declared here to 
// save time on passing parameter.
string c_name, c_vname, c_weap_name,c_verb,c_limb;
int dam;

// These strings are handled by many functions, declared here to save time
// on passing parameter
string c_msg_attacker, c_msg_defender, c_msg_others;

// Ok, these are the message generators
 generate_action_message()
{
	c_msg_attacker	= sprintf("%s"+c_verb, "��", c_weap_name, c_vname + c_limb);
	c_msg_defender	= sprintf("%s"+c_verb, c_name, c_weap_name, "��" + c_limb);
	c_msg_others 	= sprintf("%s"+c_verb, c_name, c_weap_name, c_vname + c_limb);
}

 generate_miss_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "������û��.��\n";
		c_msg_defender	+= "������û��.��\n";
		c_msg_others 	+= "������û��.��\n";
	} else {
		c_msg_attacker	+= "û����.\n";
		c_msg_defender	+= "û����.��\n";
		c_msg_others 	+= "û����.��\n";
	}
}

 generate_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "�����Ǳ��Է�����.��\n";
		c_msg_defender	+= "�����Ǳ������.��\n";
		c_msg_others 	+= "�����Ǳ�"+c_vname+"����.��\n";
	} else {
		c_msg_attacker	+= "���Է�����.��\n";
		c_msg_defender	+= "�������.��\n";
		c_msg_others 	+= "��"+c_vname+"����.��\n";
	}
}

 generate_unarmed_parry_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "�����Ǳ��Է����ָ�.��\n";
		c_msg_defender	+= "�����Ǳ������ָ�.��\n";
		c_msg_others 	+= "�����Ǳ�"+c_vname+"���ָ�.��\n";
	} else {
		c_msg_attacker	+= "���Է����ָ�.��\n";
		c_msg_defender	+= "�������ָ�.��\n";
		c_msg_others 	+= "��"+c_vname+"���ָ�.��\n";
	}
}

 generate_dodge_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "�����Ǳ��Է��㿪��.��\n";
		c_msg_defender	+= "�����Ǳ���㿪��.��\n";
		c_msg_others 	+= "�����Ǳ�"+c_vname+"�㿪��.��\n";
	} else {
		c_msg_attacker	+= "���Է��㿪��.��\n";
		c_msg_defender	+= "����㿪��.��\n";
		c_msg_others 	+= "��"+c_vname+"�㿪��.��\n";
	}
}

 generate_block_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "�����Ǳ��Է��öܵ���.��\n";
		c_msg_defender	+= "�����Ǳ����öܵ���.��\n";
		c_msg_others 	+= "�����Ǳ�"+c_vname+"�öܵ���.��\n";
	} else {
		c_msg_attacker	+= "���Է��öܵ���.��\n";
		c_msg_defender	+= "�����öܵ���.��\n";
		c_msg_others 	+= "��"+c_vname+"�öܵ���.��\n";
	}
}

 generate_no_penetrate_message(int defend)
{
	if( !defend ) {
		c_msg_attacker	+= "������û������κ��˺�.��\n";
		c_msg_defender	+= "������û������κ��˺�.��\n";
		c_msg_others	+= "������û������κ��˺�.��\n";
	} else {
		c_msg_attacker	+= "û������κε��˺�.��\n";
		c_msg_defender	+= "û������κε��˺�.��\n";
		c_msg_others	+= "û������κε��˺�.��\n";
	}
}

 generate_hit_message(int defend)
{
	string c_dmsg;

	if( !defend ) c_dmsg = "��";
	else c_dmsg = "";
	if( dam < 3 ) {
		if( !defend ) c_dmsg += "����ֻ���Ա߲���.��\n";
		else c_dmsg += "ֻ�Ǵ��Ա߲���.��\n";
	} else if( dam < 6 ) {
		c_dmsg += "�����΢���˺�.��\n";
	} else if( dam < 10 ) {
		c_dmsg += "���һЩ�˺�.��\n";
	} else if( dam < 15 ) {
		c_dmsg += "��ɲ����˺�.��\n";
	} else if( dam < 20 ) {
		c_dmsg += "������ص��˺�.��\n";
	} else if( dam < 27 ) {
		c_dmsg += "�����Ϊ���ص��˺�.��\n";
	} else if( dam < 35 ) {
		c_dmsg += "����൱���ص��˺�.��\n";
	} else if( dam < 45 ) {
		c_dmsg += "���ʮ�����ص��˺�.��\n";
	} else if( dam < 60 ) {
		c_dmsg += "��ɷǳ����ص��˺�.��\n";
	} else {
		c_dmsg += "��ɼ������ص��˺�.��\n";
	}
	c_msg_attacker	+= c_dmsg;
	c_msg_defender	+= c_dmsg;
	c_msg_others	+= c_dmsg;
}

// This is the 
varargs void report_combat(object attacker, object defender, int damage, object weapon)
{
	int i, defend;
	string msg, func,weap_type;
	object *obs;
	//add by ca
/*	string dd;
	damage=damage+random(100);
dd="damage="+ damage +"\n";
write(dd);*/
//end add 
	c_name = attacker->query("c_name");
	c_vname = defender->query("c_name");
	
	if( weapon ) c_weap_name = weapon->query("c_name");
	else c_weap_name = "";

	c_verb = (string)attacker->get_c_verb();

	if( !c_verb ) {
		if( !weapon || !(weap_type = weapon->query("type")) || undefinedp(c_dflt_verbs[weap_type]) )
			weap_type = "unarmed";

		if( !c_verb )
			c_verb = c_dflt_verbs[weap_type][ random(sizeof(c_dflt_verbs[weap_type]))];
	}

	c_limb = defender->get_c_limb();
	if( !c_limb ) c_limb = c_dflt_limbs[random(sizeof(c_dflt_limbs))];
	dam = damage;

	// Deceide how the hit looks like.
	generate_action_message();
	defend = 0;
	if( func = (string)defender->query("defense_skill") ) {
		msg = DEFENSE_SKILL(func)->query_defense_msg(defender, attacker);
		if( msg ) {
			c_msg_attacker	+= sprintf("����"+msg+"�����", c_vname);
			c_msg_defender	+= sprintf("����"+msg+"�����", "��");
			c_msg_others 	+= sprintf("����"+msg+"�����", c_vname);
			defend = 1;
		}
	}
	if( damage > 0 )
		generate_hit_message(defend);
	else if( damage==0 )
		generate_no_penetrate_message(defend);
	else if( damage==-1 )
		generate_miss_message(defend);
	else if( damage==-2 )
		generate_parry_message(defend);
	else if( damage==-3 )
		generate_block_message(defend);
	else if( damage==-4 )
		generate_dodge_message(defend);
	else if( damage==-5 )
		generate_unarmed_parry_message(defend);

	// Send message to attacker
	if( defender ) {
		attacker->quick_message(c_msg_attacker);
//		message( "combat", c_msg_attacker, attacker );
		if( damage > 0 ) 
			attacker->quick_message(sprintf( "( %s%s )\n",
				c_vname, STATS_D->status_string(defender) ) );
		
//			message( "combat", sprintf( "( %s%s )\n",
//				c_vname, STATS_D->status_string(defender) ), attacker );
	} 

	// Send message to defender
	if( defender ) {
		defender->quick_message(c_msg_defender);
//		message( "combat", c_msg_defender, defender );
		if( damage > 0 ) 
			defender->quick_message(sprintf( "( ��%s )\n",
				STATS_D->status_string(defender) ) );
//			message( "combat", sprintf( "( ��%s )\n",
//				STATS_D->status_string(defender) ), defender );
	} 

	// Send message to others
	obs = all_inventory(environment(attacker))- ({ attacker,defender });
	for ( i = sizeof(obs) -1 ; i >= 0 ; i -- ) 
		if ( living(obs[i]) )
			obs[i]->quick_message(c_msg_others);
/*
	tell_room( environment(attacker), 
		c_msg_others,
		({ attacker, defender }) );
*/
}

void report_death()
{
	int i;
	object me, *ob;
	string c_msg;

	me = previous_object();
	if( !stringp(c_msg = me->query("c_death_msg")) )
		switch( random(5) )	{
			case 0: 
				c_msg = "%sҡҡ�λε����˼��������ڵ��� ... ����.��\n";
				break;
			case 1: 
				c_msg = "%s����һ�������ĲҽУ����ڵ��� ... ����.��\n";
				break;
			case 2: 
				c_msg = "%s�ȳ�������Ѫ�����ڵ� ... �ۿ������.��\n";
				break;
   /* bmp�������*/   case 3:
                                c_msg = "%sֱ���ȵ�����һ�� ... ���ˡ�\n";
                                break;
                        case 4:
                                c_msg = "%s���������һ˿��Ѫ����������һ�� ... ���������ˡ�\n";
                                break;
 		}
	if ( !environment(me) ) return ;
	ob = all_inventory( environment(me) );
	i = sizeof(ob);
	while(i--) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		message( "combat", sprintf( c_msg, me->query("c_name") ), ob[i] );
	}
}
