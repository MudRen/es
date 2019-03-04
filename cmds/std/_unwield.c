//#pragma save_binary

// _unwield.c
// Command to unwield weaponry.
// Mobydick@TMI-2, 9/17/92

#include <mudlib.h>  

inherit DAEMON ;

int cmd_unwield(string str) {

	object obj, firstwep, secondwep ;
	string name ;
	int class1 ;

	if (!str) {
		notify_fail ("��Ҫ������������?\n") ;
		return 1 ;
	}
	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("��û�� "+str+".\n") ;
		return 0 ;
	}
	class1 = obj->query("weapon_class") ;
	if (!class1) {
		notify_fail ("�ǲ�������.\n") ;
		return 0 ;
	}
	this_player()->block_attack(2) ;
	firstwep = this_player()->query("weapon1") ;
	secondwep = this_player()->query("weapon2") ;
	if (obj==firstwep || obj==secondwep) {
// Unwield it in this case.
// The unwielding code is in the weapon object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unwield();
		this_player()->calc_weapon_class();
		return 1 ;
	}
	notify_fail("�㲢û��װ����������.\n") ;
	return 0 ;
}

int help() {
	write (@HELP
ʹ�ø�ʽ: unwield <������>

�����װ��������.

���ָ��: wield
HELP
);
	return 1 ;
}
