//#pragma save_binary

// File: /cmds/std/_unsecure.c
// by Kyoko, 08-06-1994

#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON;

int help();

int cmd_unsecure(string str)
{
	object player, *inv, ob;
	int i;
	string type;
	
    player = this_player();
	
	if(!str) return help();

	player->block_attack(2);

	if( str == "all" ) {
		inv = all_inventory(player);
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("������û���κζ����ɳ�ȥ��ǡ�\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ) continue;
			if( inv[i]->query("secure") ) {
				tell_object( player, 
					inv[i]->query("short")+"("+inv[i]->query("name")+
					")"+" --> ���߱�ǡ�\n" );
				inv[i]->delete("secure");
			}
		}
		write( "Ok.\n" );
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		inv = filter_array(all_inventory(player), "is_this_type",
			this_object(), type );
		if( !pointerp(inv) || sizeof(inv) < 1 )
			return notify_fail("������û�����ණ���ɳ�ȥ��ǡ�\n");
		for( i=0; i<sizeof(inv); i++) {
			if( !inv[i] || inv[i]->query("prevent_drop") ) continue;
			if( inv[i]->query("secure") ) {
				tell_object( player, 
					inv[i]->query("short")+"("+inv[i]->query("name")+
					")"+" --> ���߱�ǡ�\n" );
				inv[i]->delete("secure");
			}
		}
		write( "Ok.\n" );
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("������û������������\n");
	if( !ob->query("secure") )
		return notify_fail("����������δ���趨��ǡ�\n");
	tell_object( player,
		ob->query("short")+"("+ob->query("name")+
		")"+" --> ���߱�ǡ�\n" );
	ob->delete("secure");
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
	  write("ʹ�ø�ʽ: unsecure <item | all [type of items] | all>.\n\n"+
	     "�������ָ��, ����Խ���ȥ��Ʒ�ı�ǡ�\n"+
	     "See also: secure.\n\n"
	  );
	return 1;
}
