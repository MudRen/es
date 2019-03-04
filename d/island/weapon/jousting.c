/*
 * Ô­×÷Õß£ºIshige (1995.1)
 * ÐÞ¸ÄÕß£ºIshige (1995.12)
 */

#include <mudlib.h>

inherit WEAPON;

string C_NAME=("[36;1m¡õ[0;36m¡õ[36;1m¡õ[0;36m@[36;1m¡õ[0;36m¡õ[36;1m¡õ[0;36mu[37m");
void create()
{
	set_name( "Ultima Trident",C_NAME );
	add( "id",({ "jousting","trident" }) );
	set_short( C_NAME );
	set_long(@LONG
	ÕâÊÇ°ÑÊÀ¼äº±¼ûµÄÉñ±øÀûÆ÷£¬ÓµÓÐÕâ°ÑÉñ±øÀû
	Æ÷ÊÇÐí¶àÆïÊ¿ÖÕÉú×î´óµÄÔ¸Íû£¬Ö»¿ÉÏ§ÒÑ¾­²»
	ÖªµÀÓÐ¶àÉÙÈËÎªÁËÕâ°ÑÉñ±øÀûÆ÷¶øÉ¥Ê§±¦¹óµÄ
	ÐÔÃü¡£
LONG
		);
	set( "unit","°Ñ" );
	set( "type","jousting" );
	set( "weapon_class",45 );
        set( "min_damage",25 );
        set( "max_damage",52 );
	set( "weight",200 );
	set( "value",({ 5600,"silver" }) );
	set( "nosecond",1 );
	set( "prevent_insert",1 );
	set( "hit_func","hit_fun" );
}

string ex_look(){
return (set_color("$N","HIY")+"ÊÖÉÏµÄ"+C_NAME+"ÓÐ¹É[31;5m¿ªÌì±ÙµØ[37;0mµÄÆøÊÆ£¡\n$N¿´ÆðÀ´ÓÐÈç"+set_color("ÌìÉñ½µÊÀ","HIB")+"Ò»°ã¡£\n" );
}

void wi_fun()
{
	set("extra_look","@@ex_look");
	return;
}

void unwi_fun()
{
	delete( "extra_look");
	return;
}

int hit_fun(object victim,int dis)
{
	object holder;
	int dam,skill,point;
	string name1,name2;
	
	if( !victim ) return 0;
	if( !(holder=environment( this_object() )) || !living(holder) ) return 0;
	if( !(holder->query("justice")) ) return 0;
	point = (int)holder->query("justice");
//	if( point < random (2000) ) return 0;
	if( point <= 1000 ){ dam=5; }
	else if( point > 1000 && point <= 3000 ){ dam=10; }
	else if( point > 3000 && point <= 8000 ){ dam=20; }
	else if( point > 8000 && point <= 17000 ){ dam=30; }
	else if( point > 17000 && point <= 60000 ){ dam=40; }
	else if( point > 60000 ){ 50; }
	
	skill=(int)holder->query_skill("jousting");
	name1=holder->query("c_name");
	name2=victim->query("c_name");
	
	if( random(100) > (15+(skill-100)) ) return 0;
	
	tell_room(environment(victim),"\n"+C_NAME+"µÄ"+set_color("ÉñÊ¥Á¦Á¿","HIW")+"£¬¼¤·¢ÁË"+name1+"µÄÁ¦Á¿£¬¶Ô"+name2+"Ôì³ÉÁË[34;1;5m¡¸ÄÑÒÔ¹À¼Æ¡¹[37;0mµÄÉËº¦¡£\n\n",holder);
	tell_object(holder,"\n"+set_color("ÉñÊ¥µÄÁ¦Á¿","HIW")+"³äÂúÁËÄãµÄÉíÇû£¬Äã·¢³öÁË"+set_color("¡¸³¬ºõÏëÏñ¡¹","HIC")+"µÄÒ»»÷£¡\n\n" );
	holder->add("justice",-4);
	victim->receive_special_damage( "divine", dam );
	victim->set("last_attacker",holder);
	return dam;
}
