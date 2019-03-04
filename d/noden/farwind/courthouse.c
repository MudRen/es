//#pragma save_binary

// A courthouse where people can get married and you can check out the
// list of marriages.
// Due to TMI's strict non-sectarian policy (and, probably, the fact that
// so many of the coders are from California,"Go Bears :)") marriages take
// place here rather than in a church or synagogue or what-have-you. You can
// change it if you feel you must... :)

#include "farwind.h"
#define MARRIAGE_FILE "d/noden/data/marriages.o"

inherit ROOM;

string *couples, *pending;
int i, j, numcouples, numpending;
string str ;

void add_pending(string str);
void perform_marriage(string s1, string s2);

void create()
{
	::create();
	seteuid(getuid()) ;
	set("objects", ([ "justice" : FARWIND"monster/justice" ]) );
	reset() ;
	set ("light", 1) ;
	set ("short", "��Ժ");
	set ("long", 
			"����������Զ����ķ�Ժ����Ժ��ķ��ٿ���Ϊ�����İ���֤�飬��\n"
		"��������������飬Զ������˽�������Ϊһ����ʥ�����ַ���������Լ��\n"
		"��Ҫ�����ˣ��� help marriage �Եõ���һ����˵����\n");
	set ("exits", ([ "south" : FARWIND"ebazz" ]) ) ;
	numpending = 0 ;
	pending = allocate(10) ;
	str = read_file(MARRIAGE_FILE,1,1) ;
	if (!str) {
		numcouples = 0 ;
		couples = allocate(1) ;
		return ;
	}
	if (sscanf(str,"%d",numcouples)!=1) {
		write ("Marriages file corrupt! Tell a wizard!\n") ;
		return ;
	}
	couples = allocate(numcouples+1) ;
	for (i=0;i<numcouples;i++) {
		str = read_file(MARRIAGE_FILE,i+2,i) ;
		sscanf (str,"%s\n",couples[i]) ;
	}
}

void init()
{
	add_action("list_couples", "couples") ;
	add_action("married_to_whom","spouse") ;
	add_action("get_married", "marry") ;
	add_action("help_me", "help") ;
}

int help_me(string str)
{
if (str=="marriage") {
	write(
"To get married, both MUDders should come to the court house and\n"+
"type 'marry <spouse>'. When both have typed it, the marriage will\n"+
"be performed.\n"+
"Type 'couples' to get a list of recent marriages, or 'spouse\n"+
"<name>' to find out who's married to whom.\n") ;
	return 1 ;
}
return 0 ;
}

int list_couples()
{
	int i ;
	string s1, s2, date ;

	if (numcouples==0) {
		write("���ڲ�û���κ���ʽ�Ǽǵķ��� ....��\n");
		return 1 ;
	}
	for (i=0;i<numcouples;i++) {
		sscanf( couples[i],"%s-%s %s",s1, s2, date);
		write( s1+" and "+s2+" got married at "+date+".\n");
	}
	return 1 ;
}

string find_spouse (string fellow)
{
	object spouse ;
	string s1,s2,s3 ;

	if (numcouples==0) return "none";
	for (i=0; i<numcouples; i++) {
		sscanf(couples[i], "%s-%s %s", s1, s2, s3);
		if (s1==capitalize(fellow)) return s2;
		if (s2==capitalize(fellow)) return s1;
	}
	return "none" ;
}

int married_to_whom (string str)
{
	string spouse;

	if (!str) str = this_player()->query("name") ;
	spouse = find_spouse(str) ;
	if (spouse=="none") {
		write( capitalize(str)+" ���ڻ��ǵ���û�н���顣\n");
		return 1 ;
	}
	write( capitalize(str)+" ����ż�� "+spouse+"��\n");
	return 1 ;
}

int get_married (string str)
{
	object person;
	string s1,s2;

	if (!str) {
		notify_fail("��Ҫ��˭��飿\n") ;
		return 0 ;
	}
	if(capitalize(str)==(string)this_player()->query("name")) 
	return notify_fail( "���Լ���飿�����⣬�����������в�ͨ��\n");

        if ( (string)this_player()->query("class") == "monk" )
	return notify_fail(
	"���ٿ�������������ⲻ�����ĳ����� !! ���չ����Ҹ�Ů�𣿡�\n" );

	person = present( "justice", this_object() );
	if (!person) {
		write("���취�ٲ��ڣ������������");
		return 1 ;
	}
	if( this_player()->query("spouse") )
		return notify_fail("���Ѿ�������ˣ�\n") ;
	if( find_spouse(capitalize(str))!="none" )
		return notify_fail( capitalize(str) + " �Ѿ�������� ....��\n");
	if( !find_player(str) || !present(str, environment(this_player())) )
		return notify_fail("��Ľ����������� ....��\n");
	if (numpending==0) {
		add_pending(str) ;
		return 1 ;
	}
	for( i=0; i<numpending; i++) {
		sscanf(pending[i],"%s-%s", s1, s2) ;
		if( capitalize(str)==s2 && (string)this_player()->query("name") == s1) {
			perform_marriage(s1, s2);
			if (i==numpending) {
				numpending = numpending - 1 ;
				return 1 ;
			}
			for (j=i+1;j<numpending;j++) {
				pending[j-1]=pending[j] ;
			}
			numpending = numpending - 1 ;
			return 1 ;
		}
	}
	add_pending(str);
	return 1 ;
}

int add_pending(string str)
{
	string str2 ;
	object fiancee ;

	if (numpending==10)
		return notify_fail(
			"���ڵȴ���������̫���ˣ�����æ��������������������\n");
	str2 = this_player()->query("name") ;
	pending[numpending] = capitalize(str)+"-"+str2 ;
	numpending = numpending + 1 ;
	write( "���ٽ�������ת��� " + capitalize(str) + "��\n");
	fiancee = find_player(str) ;
	tell_object( fiancee, 
		str2 + " ͸�����ٶ��������ʽ����飡");
}

int perform_marriage(string s1, string s2)
{
	object spouse ;

	spouse = find_player(lower_case(s2)) ;
	if (!spouse)
		return notify_fail( 
			"��Ľ������Ѿ��뿪�ˡ��������¡����޷����л���\n");
	spouse->set( "spouse", s1);
	this_player()->set( "spouse", s2);

	tell_object(spouse, 
		"��ϲ��˫����Ͷ��ϣ�����������ʽ������� "+s1+" ��Ϊ�Ϸ����ޣ�\n");
	write( 
		"��ϲ��˫����Ͷ��ϣ�����������ʽ������� "+s2+" ��Ϊ�Ϸ����ޣ�\n");
	shout("������Զ����Ľ������������ص������� .... \n"+
	      "·���Ƕ���������������ϲ������� !! ף�� "+capitalize(s1)+" �� "+capitalize(s2)+
	      " ��Զ�Ҹ����� !!��\n"); 
	couples[numcouples] = s1+"-"+s2+" "+ctime(time());
	numcouples++;

	rm(MARRIAGE_FILE) ;
	write_file(MARRIAGE_FILE, numcouples+"\n") ;
	for (i=0;i<numcouples;i++)
		write_file (MARRIAGE_FILE, couples[i]+"\n") ;
	return 1;
}
