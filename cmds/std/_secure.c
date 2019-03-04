//#pragma save_binary

// File: /cmds/std/_secure.c
// by Kyoko, 06-06-1994

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON;

int help();

int cmd_secure(string str)
{
	object player, *inv, ob;
	int chinese_mode, i;
	string type;
	
    player = this_player();
	chinese_mode = can_read_chinese();
	
	if(!str) return help();

	player->block_attack(2);

	if(str == "all") {
		inv = all_inventory(player);
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("������û���κζ����ɱ�ǡ�\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player,
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> �趨��ǡ�\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		inv = filter_array(all_inventory(player), "is_this_type",
			this_object(), type );
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("������û�����ණ���ɱ�ǡ�\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			tell_object( player, 
				inv[i]->query("short")+"("+inv[i]->query("name")+
				")"+" --> �趨��ǡ�\n" );
			inv[i]->set("secure", 1);
		}
		write( "Ok.\n" );
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("������û������������\n");
	if( ob->query("prevent_drop") )
		return notify_fail("�㱾�����޷�������������, ���ض��һ���ˡ�\n");
	if( ob->query("secure") )
		return notify_fail("���ѱ��趨����ˡ�\n");
	tell_object( player, 
		ob->query("short")+"("+ob->query("name")+
		")"+" --> �趨��ǡ�\n" );
	ob->set("secure", 1);
	write( "Ok.\n" );
	return 1;
}

int is_this_type(object item, string type)
{
	if( !item->id(type) || item->query("prevent_drop") ) return 0;
	return 1;
}

int help()
{
	  write("ʹ�ø�ʽ: secure <item | all [type of items] | all>.\n\n"+
	     "�������ָ��, ����Խ���Ʒ���, ���Ǳ���ǵ���Ʒ�����ᱻ���ߡ�\n"+
	     "����: give, drop, sell & toss ��Щָ����Զ��������б���ǵ�\n"+
	     "��Ʒ��������� unsecure ��������ߡ�\n"+
	     "See also: unsecure��\n\n"
	  );
	return 1;
}
