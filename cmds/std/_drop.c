//#pragma save_binary

// File: /cmds/std/_drop.c
// based on TMI-2 version
// completely rewritten...cleaned up...modified
// by Zeus, 13-03-1993
// updated for credit() and debit() by Annihilator 11-03-1993

#include <mudlib.h>
#include <money.h>
#include <move.h>
#define WIZARD_DROP     1

inherit DAEMON;

int help();

int cmd_drop(string str)
{
	mapping coins;
	object *inv, ob, env, player;
	int res, amount, capac, i, money, is_wizard;
	string short, *types, type, word, tmp, unit, c_name, cap_name, name;

    player = this_player();
    env = environment(player);
	c_name = (string)player->query("c_name");
	name = (string)player->query("name");
    if( !WIZARD_DROP || !wizardp(player) || member_group(name, "admin") ||
        member_group(name, "arch") ) is_wizard = 0;
    else is_wizard = 1;
	
	if( !str ) return help();
	if( !env )
		return notify_fail("��û�а취�����ﶪ�κζ�����\n");

	player->block_attack(2);
	if(sscanf(str, "%d %s %s", amount, type, tmp) == 3 ||	
	sscanf(str, "%d %s", amount, type) == 2) {
		if( !player->debit( type, amount) )
			return notify_fail( 
				"��û�������"+to_chinese(type+" coin")+"��\n"
				);
		ob = clone_object(COINS);
		ob->set_type(type);
		ob->set_number(amount);
		res = ob->move(env);
		if( res != MOVE_OK ) {
			player->credit( type, amount );
			ob->remove();
			return notify_fail( 
				"�㲻���ٶ������ˡ�\n");
		}
		if(amount == 1) word = "coin"; else word = "coins";
		write( "�㶪�� "+amount+" ö"+to_chinese(type+" coin")+"��\n"
			);
		tell_room( env, 
		c_name+"����һЩ"+to_chinese(type+" coin")+"��\n", player);
		if( is_wizard ) {
		    tell_room( env, 
			  "������һ�¾���ʧ�ˡ�\n"
		    );
		    ob->remove();
		}
		return 1;
	}

	if( str == "all" ) {
		inv = all_inventory(player);
		if( !pointerp(inv) && sizeof(inv)<1 )
			return notify_fail( 
				"������û���κζ����ɶ���\n");
		for( i=0; i<sizeof(inv); i++ ) {
			if( !inv[i] || inv[i]->query("prevent_drop") ||
				inv[i]->query("secure") ) continue;
			res = inv[i]->move(env);
			if( !inv[i] || res != MOVE_OK ) continue;

			short = (string)inv[i]->query("short");
			if( !(unit = inv[i]->query("unit")) ) unit = "��";
			if( !short ) short = "ĳ��";
			write( sprintf("�㶪��һ%s%s��\n",unit,short));
			tell_room( env, 
				sprintf("%s����һ%s%s��\n",c_name,unit,short), player
			);
			inv[i]->delete("on_mounted");
			if( is_wizard ) {
			  tell_room( env, 
			    "������һ�¾���ʧ�ˡ�\n", player
		      );
			  inv[i]->remove();
			}
		}
		write( "�㽫���������ܶ��Ķ������¡�\n");
		return 1;
	}
	if(str == "all coins") {
		coins = player->query("wealth");
		if(!mapp(coins) || sizeof(coins) == 0)
			return notify_fail(
				"������û���κ�Ǯ�ҡ�\n");
		types = keys(coins);
		if(!pointerp(types) || sizeof(types) == 0) 
			return notify_fail(
			"������û���κ�Ǯ�ҡ�\n");

		for(i = 0; i < sizeof(types); i++) {
			money = coins[types[i]];
			if(money == 0) continue;
			player->debit( types[i], money );
			ob = clone_object(COINS);
			if (!ob) { 
				write("Ǯ�ҷ�������,��֪ͨ��ʦ���� !!\n");
			    continue;
			}  
			ob->set_type(types[i]);
			ob->set_number(money);

			res = ob->move(env);

			if(res != MOVE_OK) {
				player->credit( types[i],money );
				ob->remove();
				continue;
			}
			if(money == 1) word = "coin"; else word = "coins";
			write( 
				"�㶪�� "+money+" ö"+to_chinese(types[i]+" coin")+"��\n");
			tell_room( env, 
				c_name+"����һЩ"+to_chinese(types[i]+" coin")+"��\n",player
			);
			if( is_wizard ) {
			  tell_room( env, 
			    "������һ�¾���ʧ�ˡ�\n"
		      );
			  ob->remove();
			}
		}
		return 1;
	}

	if(sscanf(str, "all %s", type) == 1) {
		money = player->query("wealth/"+type);
		if(!money)
			return notify_fail(
				"������û������Ǯ�ҡ�\n");

		player->debit( type, money );
		ob = clone_object(COINS);
		ob->set_type(type);
		ob->set_number(money);
		res = ob->move(env);
		if(res != MOVE_OK) {
			player->credit( type, money );
			ob->remove();
			return notify_fail(
				"�㲻���ٶ������ˡ�\n");
		}
		write( "����������е�" + to_chinese(type+" coin")+"���¡�\n"
			);
		tell_room( env, 
			c_name+"����һЩ"+to_chinese(type+" coin")+"��\n",player
	    );
	    if( is_wizard ) {
		    tell_room( env,
			    "������һ�¾���ʧ�ˡ�\n"
		    );
			ob->remove();
		}
		return 1;
	}

	ob = present(str, player);
	if( !ob )
		return notify_fail("������û������������\n");
 
    if( ob->query("prevent_drop") || ob->query("secure") )
 		return notify_fail( "��û�а취����������\n");

	res = ob->move(env);
	if(res != MOVE_OK)
		return notify_fail( "��û�а취�����������\n");

	if( !(unit= ob->query("unit")) ) unit = "��";
	write( sprintf("�㶪��һ%s%s��\n",unit,ob->query("short")));
	tell_room( environment(this_player()), 
		sprintf("%s����һ%s%s��\n",c_name,unit,ob->query("short")),player
    );
    ob->delete("on_mounted");
    if( is_wizard ) {
		tell_room( env, 
			"������һ�¾���ʧ�ˡ�\n");
        ob->remove();
	}
	return 1;
}

int help()
{
	write(@HELP
ʹ�ø�ʽ: drop <��Ʒ����all>

�����ϵ���Ʒ���ڵ��ϣ�ĳЩ��Ʒ������ʧ.

���ָ��: get, put.
HELP
);
	return 1;
}
