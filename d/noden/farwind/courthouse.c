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
	set ("short", "法院");
	set ("long", 
			"你现在来到远风镇的法院。法院里的法官可以为你和你的爱人证婚，不\n"
		"过别想在这里离婚，远风镇的人将婚姻视为一种神圣不可侵犯的终身誓约，\n"
		"想要结婚的人，请 help marriage 以得到进一步的说明。\n");
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
		write("现在并没有任何正式登记的夫妻 ....。\n");
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
		write( capitalize(str)+" 现在还是单身，没有结过婚。\n");
		return 1 ;
	}
	write( capitalize(str)+" 的配偶是 "+spouse+"。\n");
	return 1 ;
}

int get_married (string str)
{
	object person;
	string s1,s2;

	if (!str) {
		notify_fail("你要和谁结婚？\n") ;
		return 0 ;
	}
	if(capitalize(str)==(string)this_player()->query("name")) 
	return notify_fail( "和自己结婚？好主意，不过在这里行不通。\n");

        if ( (string)this_player()->query("class") == "monk" )
	return notify_fail(
	"法官开口骂道：「你这不守清规的臭和尚 !! 想诱拐良家妇女吗？」\n" );

	person = present( "justice", this_object() );
	if (!person) {
		write("今天法官不在，请改天再来。");
		return 1 ;
	}
	if( this_player()->query("spouse") )
		return notify_fail("你已经结过婚了！\n") ;
	if( find_spouse(capitalize(str))!="none" )
		return notify_fail( capitalize(str) + " 已经结过婚了 ....。\n");
	if( !find_player(str) || !present(str, environment(this_player())) )
		return notify_fail("你的结婚对象不在这里 ....。\n");
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
			"现在等待结婚的新人太多了，法官忙不过来，请待会儿再来。\n");
	str2 = this_player()->query("name") ;
	pending[numpending] = capitalize(str)+"-"+str2 ;
	numpending = numpending + 1 ;
	write( "法官将你的求婚转告给 " + capitalize(str) + "。\n");
	fiancee = find_player(str) ;
	tell_object( fiancee, 
		str2 + " 透过法官对你提出正式的求婚！");
}

int perform_marriage(string s1, string s2)
{
	object spouse ;

	spouse = find_player(lower_case(s2)) ;
	if (!spouse)
		return notify_fail( 
			"你的结婚对象已经离开了「东方故事」，无法进行婚礼。\n");
	spouse->set( "spouse", s1);
	this_player()->set( "spouse", s2);

	tell_object(spouse, 
		"恭喜！双方情投意合，法官现在正式宣布你和 "+s1+" 成为合法夫妻！\n");
	write( 
		"恭喜！双方情投意合，法官现在正式宣布你和 "+s2+" 成为合法夫妻！\n");
	shout("你听到远风镇的教堂钟声欢欣地当当齐响 .... \n"+
	      "路人们都欢欣唱道：「恭喜这对新人 !! 祝福 "+capitalize(s1)+" 和 "+capitalize(s2)+
	      " 永远幸福快乐 !!」\n"); 
	couples[numcouples] = s1+"-"+s2+" "+ctime(time());
	numcouples++;

	rm(MARRIAGE_FILE) ;
	write_file(MARRIAGE_FILE, numcouples+"\n") ;
	for (i=0;i<numcouples;i++)
		write_file (MARRIAGE_FILE, couples[i]+"\n") ;
	return 1;
}
