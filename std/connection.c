//#pragma save_binary

//	File	:  /std/connection.c
//	Creator	:  Buddha@TMI  (1/93)
//	Updated	:  Watcher@TMI (2/28/93) to move wizard flag from user
//	object to the connection object.
//	Watcher@TMI (3/16/93) to setup new body connection system
//	Annihilator@Eastern.Stories rewrite body link method to fit
//	new race-body feature.
//
//	This is a generic user connection object which is linked
//	to a specific user body.

#include <uid.h>
#include <login.h>
#include <daemons.h>

string name, c_name, gender, password, body, email, real_name, ip, userid;
mapping domains;
mixed *passwd_fail;
int wizard, last_on, dead, hibernate;

nosave object body_ob, tmp_body;
nosave int creating_phase;

int remove();
int save_data();

//  It would be Bad (tm) to allow a connection object to be shadowed.

int query_prevent_shadow() {  return 1;  }

// This is called by master.c when a player trys to login
void logon()
{
	seteuid("Logon");
	wizard = 0;
	call_out("check_status", 2 * 60);
	LOGIN_D->logon(this_object());
}

// This is called by logind.c when a player finished login procedure
int connect()
{
	if( geteuid(previous_object()) != ROOT_UID) return 0;
	if( !body_ob ) return 0;
	if( !interactive(this_object()) ) {
		if( !interactive(body_ob) ) body_ob->remove();
		remove();
	}

	if( !exec(body_ob, this_object()) ) {
		write("无法连上你的身体!!\n");
		body_ob->remove();
		remove();
		return 0;
	}
	body_ob->set_link(this_object());
	return 1;
}

int switch_body()
{
	object pre_ob;

	pre_ob = previous_object();
	if( !tmp_body || (geteuid(pre_ob) != ROOT_UID && pre_ob != body_ob) )
		return 0;

	if( interactive(tmp_body) || !interactive(body_ob) ||
		!exec(tmp_body, body_ob) ) return 0;

	body_ob = tmp_body;
	export_uid(body_ob);
	tmp_body = 0;

	body_ob->set_link(this_object());
	body_ob->restore_body();

	return 1;
}

nomask void receive_message(string mclass, string msg)
{
	receive(msg);
}

void link_dead()
{
	save_data();
	remove();
}

// We need this function in case a player is queried for his link while he
// is in login or for some other reason has no body.
object query_link()
{
	return this_object();
}

void set_creating_phase(int flag)
{
	if( base_name(previous_object()) != NEWUSER_D ) return;
	creating_phase = flag;
}

int save_data()
{
	if( !name || name == "logon" || !password || creating_phase ) return 0;
	assure_user_save_dir(this_object());
	save_object(user_data_file(this_object()));
	return 1;
}

// This function is called by LOGIN_D to restore data of connection from
// saved file.
int restore()
{
	int success;

	if( !name ) return 0;
	seteuid(name);
	return restore_object(user_data_file(this_object()));
}

// This function is called by LOGIN_D to restore data of user body from
// saved file.
int restore_body()
{
	string race, old_save_file;
	int try_update;

	if( geteuid(previous_object()) != ROOT_UID ) return 0;
	if( !name || !body ) return 0;
	seteuid(name);

// Do this check for compatiblility to old user body. By Annihilator.
//	if( sscanf(body, VALID_BODY_FILE, race) != 1 ) {
//		write( @TEXT
// **请注意**
//    由於你的身体档案(body file)不对, 系统尝试修正。如发现错误, 请 mail 至
//           indra@coral.cis.nmctu.edu.tw ( indra@140.113.166.36 )
// TEXT
//		);
//		try_update = 1;
//	}

	if( catch( body_ob = new(body) ) )  return 0;
	export_uid(body_ob);
	if( !body_ob ) {
		write("身体档案有错误, 无法造出身体, 连接失败!!");
		return 0;
	}

	if( try_update ) {
		// This part of code tries to update player's body object and move the file.
		body_ob->restore_body();
		race = body_ob->query("race");
		if( !race ) race = "human";
		body = sprintf("/std/user_ob/%s", race);
		old_save_file = user_data_file(body_ob);
		body_ob->remove();
		body_ob = new(body);
		export_uid(body_ob);
		if( !body_ob ) {
			write("身体档案有错误, 无法造出身体, 连接失败!!");
			return 0;
		}
		return body_ob->restore_body_file(old_save_file);
	}

	return (int) body_ob->restore_body();
}

int remove()
{
	save_data();
	destruct(this_object());
	return 1;
}

int remove_user()
{
	call_out("remove", 0);
	return 1;
}

int clean_up()
{
	if( !body_ob || !interactive(body_ob) ) return remove();
	save_data();
	return 1;
}

nomask mixed query(string what)
{
	if( !what ) return 0;
	switch( what ) {
		case "name": return (name? name : "logon");
		case "c_name": return (c_name? c_name : "无名氏");
		case "cap_name": return (name ? capitalize(name) :"Logon");
		case "gender": return gender;
		case "password": return password;
		case "wizard": return wizard;
		case "body": return body;
		case "dead": return dead;
		case "tmp_body": return tmp_body;
		case "hibernate": return hibernate;
		case "real_name": return real_name;
		case "passwd_fail": return passwd_fail;
		case "email": return email;
		case "body_ob": return body_ob;
		case "last_on": return last_on;
		case "ip": return ip;
		case "userid": {
		  if( geteuid(previous_object()) != ROOT_UID ) return 0;
	 	  else return userid;
		}
		case "domains" : {
			if( geteuid(previous_object()) == ROOT_UID )
				return domains;
			else return copy(domains);
		}
		default : return 0;
	}
}

nomask void set(string what, mixed val)
{
	if( !what ) return 0;

	if( geteuid(previous_object()) != ROOT_UID &&
		previous_object() != body_ob ) return;

	switch( what ) {
		case "name": name = val; seteuid(name); break;
		case "c_name": c_name = val; break;
		case "gender": gender = val; break;
		case "password": password = val; break;
		case "wizard": wizard = val; break;
		case "passwd_fail": passwd_fail = val; break;
		case "body": body = val; break;
		case "tmp_body": tmp_body = val; break;
		case "real_name": real_name = val; break;
		case "email": email = val; break;
		case "body_ob": body_ob = val; break;
		case "hibernate": hibernate = val; break;
		case "dead": dead = val; break;
		case "domains": domains = val; break;
		case "userid": userid = val; break;
		case "last_on": last_on = val; break;
		case "ip": ip = val; break;
		default : return;
	}
	save_data();
}

int check_status()
{
	remove_call_out("check_status");

	if( interactive(this_object()) || !body_ob || !interactive(body_ob) )
		remove();

	return 1;
}
