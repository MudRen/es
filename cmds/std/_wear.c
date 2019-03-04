//#pragma save_binary

#include <mudlib.h>
#include <armors.h>

inherit DAEMON;

string equip_verb(object armor, string type)
{
	string verb;
	
	switch( armor->query("equip_level") ) {
		case 0 : verb = "˳����";   break;
		case 1 : verb = "��ǿ��";   break;
		case 2 : verb = "Ӳ������"; break;
		default : verb = "";        break;
	}
	switch( type ) {
		case "body":
		case "legs": 
		case "feet": 
		case "cloak": verb += "����"; break;
		case "head":  verb += "����"; break;
		case "arms": verb += "����"; break;
		case "misc": verb += "����"; break;
		case "finger": verb += "����"; break;
		case "hands": verb += "����"; break;
		case "globe": verb += "�ſ�"; break;
		case "shield": verb += "��������"; break;
		case "saddle": verb += "װ����"; break;
		case "kernel": verb += "����"; break;
		case "tail": verb += "����"; break;
		default: verb += "����"; break;
	}
	return verb;
}

int wear_armors(object player, object armor, int silent)
{
	object fwep, swep;
	string type, verb, equip_msg, equip_func;
	int j;
	
	type = armor->query("type");
	// Check armor type to decide it is a armor?
	if( member_array(type, ARMOR_TYPES) == -1 ) {
		tell_object(player, "�ǲ��ǻ��ס�\n");
		return 0;
	}

	// If he's already equipping it. Tell him so.
	if( armor->query("equipped") ) {
		tell_object(player, "���Ѿ������Ǽ������ˡ�\n");
		return 0;
	}
			
	// check if any he can't wear this armor.	
	if( player->block_wear(armor) ) {
		printf("�㲻�ܴ�%s !\n",armor->query("c_name"));
		return 0;
	}

	// If this is a shield, check his weapons and make sure he has a free arm.
	if( type == "shield" ) {
		fwep = player->query("weapon1");
		swep = player->query("weapon2");
		if( swep ) {
			tell_object(player, "����ֻ�ֶ�û�пա�\n");
			return 0;
		}
		if( fwep && (int)fwep->query("nosecond")==1 ) {
			tell_object(player, "�㲻��ͬʱװ���ܺ�˫��������\n"
			);
			return 0;
		}
	}

	if( player->query("armor/"+type) ) {
		tell_object(player, "���Ѿ�����ͬ���͵Ļ����ˡ�\n");
		return 0;
	}

	// when we get here, mean he can wear this armor.
	armor->equip();
	
	if ( !armor->query("equipped") ) {
		printf("�㲻�ܴ�%s !\n",armor->query("c_name"));
		return 0;
	}
	// display worn message.
	if( !silent ) {
		if( equip_msg = armor->query("equip_msg") ) {
			if( sizeof(equip_msg) < 2 ) tell_object(player, equip_msg);
			else tell_object(player, equip_msg[1] );
		} else {
			verb = equip_verb(armor, type);
			printf("��%s%s��\n",verb,armor->query("short"));
		  	tell_room( environment(player), 
			sprintf("%s%s%s��\n", player->query("c_name"),verb,armor->query("short")),player );
	    }
	}
	return 1;
}

int cmd_wear(string str, int silent)
{
	object obj, *ob;
	int i;

	if( !str || str == "" )
		return notify_fail("װ��ʲ�Ụ�ף�\n");

	if( str=="all" ) {
		this_player()->block_attack(10);
		ob = all_inventory(this_player());
		for( i=0; i<sizeof(ob); i++ ) {
			if( !(ob[i]->query("armor_class") || ob[i]->query("defense_bonus"))
			   || ob[i]->query("equipped") 
			   || this_player()->query("armor/"+(string)ob[i]->query("type")) )
			    continue;

	//		write("װ�� "+ob[i]->query("short")+" -> ");
			wear_armors(this_player(), ob[i], silent);
		}
		this_player()->calc_armor_class();
		write("Ok.\n");
		return 1;
	}
	
	this_player()->block_attack(4);
	obj = present(str, this_player());
	if( !obj ) 
		return notify_fail(sprintf("������û���κν���%s�Ķ�����\n",str));
	wear_armors(this_player(), obj, silent);
	this_player()->calc_armor_class();
	return 1;
}

int help()
{
	write (@HELP
Usage: wear <����>
���ָ��������㴩�ϸ��ֻ��� -- ������ְҵ����������\�Ļ�.
���ߵ������кܶ���, �йػ�������, ���Ƶ����� help armor_types 
��ѯ. 
���ָ��: remove, wield, unwield.
HELP
	);
	return 1 ;
}
