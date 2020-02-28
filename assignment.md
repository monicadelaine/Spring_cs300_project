::: {.WordSection1}
**CS300 Spring 2020**

**Programming Project**

**Due: Monday March 23 @ 12pm**

 

[You will complete a multithreaded two process system that communicates
via System V message queues.[  ]{style="mso-spacerun:yes"}The goal is to
find the longest word that begins with the supplied prefix in a series
of text passages.]{style="mso-bidi-font-weight:bold"}

[]{style="mso-bidi-font-weight:bold"}

 

**[Search Manager Logic]{style="font-size:10.0pt"}**

*[Search manager]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}*[
reads one or more prefixes from the command line, creates and sends
prefix request messages (contains prefix string and prefix ID) via
System V [ipc]{.SpellE} queues and waits for the *passage processor* to
return a series of responses.[  ]{style="mso-spacerun:yes"}The search
manager will print the results for each prefix as once all responses for
that prefix have been received.[  ]{style="mso-spacerun:yes"}Use the
passage count on the first response to determine how many responses
should be received. The *search manager* will send a message to *passage
processor* letting the processor know that all the requests have been
sent and the passage processor can terminate once all responses have
been sent.[  ]{style="mso-spacerun:yes"}Once all the responses are
received, the *search manager* should terminate.[ 
]{style="mso-spacerun:yes"}*Search manager* will print a status of the
requests when a SIGINT is received.[ 
]{style="mso-spacerun:yes"}]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[]{style="mso-bidi-font-weight:bold"}

 

**[Format:]{style="font-size:8.0pt;font-family:\"Courier New\""}**[./[searchmanager]{.SpellE}
\<secs between sending prefix requests\> \<prefix1\> \<prefix2\>
...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[./[searchmanager]{.SpellE} 3 con pre
[wor]{.SpellE}]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Message(1): \"con\" Sent (8
bytes)]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Report \"con\"]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 0 - Sense\_And\_Sensibility.txt -
constant]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 1 - Mansfield\_Park.txt -
contemptible]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 2 - The\_Call\_Of\_The\_Wild.txt! - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 3 - Tale\_Of\_Two\_Cities.txt - [
]{style="mso-tab-count:1"}[ ]{style="mso-spacerun:yes"}no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 4 - Peter\_Pan.txt - conspicuous
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Message(2): \"pre\" Sent (8
bytes)]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Report \"pre\"]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 0 - Sense\_And\_Sensibility.txt - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 1 - Mansfield\_Park.txt -
predict]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 2 - The\_Call\_Of\_The\_Wild.txt! - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 3 - Tale\_Of\_Two\_Cities.txt - [
]{style="mso-tab-count:1"}preserves]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 4 - Peter\_Pan.txt - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Message(3): \"[wor]{.SpellE}\" Sent (8
bytes)]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Report
\"[wor]{.SpellE}\"]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 0 - Sense\_And\_Sensibility.txt - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 1 - Mansfield\_Park.txt - world
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 2 - The\_Call\_Of\_The\_Wild.txt1 - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 3 - Tale\_Of\_Two\_Cities.txt - [
]{style="mso-tab-count:1"}worst
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Passage 4 - Peter\_Pan.txt - no word
found]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[      
]{style="mso-tab-count:1"}]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Message(0): \"[   ]{style="mso-spacerun:yes"}\" Sent (8
bytes)]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[Exiting \...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[SIGINT captures [Ctl]{.SpellE}-C to print
status]{style="font-size:10.0pt;mso-bidi-font-size:12.0pt"}

[[![Text Box: \*\* status before responses
received](project.fld/image001.png){width="127"
height="21"}]{style="position:absolute;left:74px;
top:-186px;width:127px;height:21px"}]{style="mso-ignore:vglayout;position:
relative;z-index:251659264"}[\^C con --
pending]{style="font-size:8.0pt;font-family:\"Courier New\""}

[pre -- pending]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[wor]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ --
pending]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[[![Text Box: \*\* status after con completes and during pre
responses](project.fld/image002.png){width="131"
height="30"}]{style="position:absolute;left:71px;
top:-200px;width:131px;height:30px"}]{style="mso-ignore:vglayout;position:
relative;z-index:251661312"}[\^C con --
done]{style="font-size:8.0pt;font-family:\"Courier New\""}

[pre -- 3 of 5]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[wor]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ --
pending]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="font-size:8.0pt;font-family:\"Courier New\""}

 

[]{style="mso-bidi-font-weight:bold"}

 

**[Passage Processor logic]{style="font-size:10.0pt"}**

[The passage processor will read a series of passage file names from
passages.txt.[  ]{style="mso-spacerun:yes"}A thread will be created for
each passage that builds [Trie]{.SpellE} with words in the passage text,
receives requests for longest word searches, searches the
[trie]{.SpellE} for the longest word and asynchronously returns the
longest word.[  ]{style="mso-spacerun:yes"}The Passage Processor will
read each prefix request from the System V [ipc]{.SpellE} queue using a
Java Native Call, sends the requests to each worker, retrieves responses
from each worker and sends them back to the search manager via the
system V queue.[  ]{style="mso-spacerun:yes"}For each prefix request,
the [trie]{.SpellE} should be searched for the longest word that starts
with that prefix.[  ]{style="mso-spacerun:yes"}In the case that a word
is found, the longest word will be sent to the [SearchManager]{.SpellE}
via the System V [ipc]{.SpellE} queue via a Java Native call.[ 
]{style="mso-spacerun:yes"}The response will include the prefix id, the
passage id, the passage name, the number of passages, present = 1, and
the longest word.[  ]{style="mso-spacerun:yes"}In the case that the
prefix is not found, the response will include the prefix id and present
= 0.]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[]{style="mso-bidi-font-weight:bold"}

 

**[Format: ]{style="font-size:8.0pt;font-family:\"Courier New\""}**[java
-cp . -[Djava.library.path]{.SpellE}=./[edu]{.SpellE}/cs300
edu.cs300.TextSamples]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="mso-bidi-font-weight:bold"}

 

[anderson\@cs426: java -cp .
-[Djava.library.path]{.SpellE}=./[edu]{.SpellE}/cs300
edu.cs300.TextSamples
2\>/dev/null]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-0 (Sense\_And\_Sensibility.txt) thread started
\...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-1 (Mansfield\_Park.txt) thread started
\...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-2 (The\_Call\_Of\_The\_Wild.txt) thread started
\...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-4 (Peter\_Pan.txt) thread started
\...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[\*\*prefix(1) con
received]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-2 1:con ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-3 (Tale\_Of\_Two\_Cities.txt) thread started
\...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-3 1:con ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 2 of 5 on 1:con from
The\_Call\_Of\_The\_Wild.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 3 of 5 on 1:con from
Tale\_Of\_Two\_Cities.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-1 1:con ==\>
contemptible]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-4 1:con ==\>
conspicuous]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 1 of 5 on 1:con from
Mansfield\_Park.txt present=1
[lw]{.SpellE}=contemptible([len]{.SpellE}=12)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 4 of 5 on 1:con from Peter\_Pan.txt
present=1 [lw]{.SpellE}=conspicuous([len]{.SpellE}=11)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-0 1:con ==\>
constant]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 0 of 5 on 1:con from
Sense\_And\_Sensibility.txt present=1
[lw]{.SpellE}=constant([len]{.SpellE}=8)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[\*\*prefix(2) pre
received]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-2 2:pre ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-0 2:pre ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 2 of 5 on 2:pre from
The\_Call\_Of\_The\_Wild.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 0 of 5 on 2:pre from
Sense\_And\_Sensibility.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-4 2:pre ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 4 of 5 on 2:pre from Peter\_Pan.txt
present=0 [lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-1 2:pre ==\>
predict]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 1 of 5 on 2:pre from
Mansfield\_Park.txt present=1 [lw]{.SpellE}=predict([len]{.SpellE}=7)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-3 2:pre ==\>
preserves]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 3 of 5 on 2:pre from
Tale\_Of\_Two\_Cities.txt present=1
[lw]{.SpellE}=preserves([len]{.SpellE}=9)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[\*\*prefix(3) [wor]{.SpellE}
received]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-1 3:wor ==\>
world]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-3 3:wor ==\>
worst]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-0 3:wor ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Worker-2 3:wor ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 1 of 5 on 3:wor from
Mansfield\_Park.txt present=1 [lw]{.SpellE}=world([len]{.SpellE}=5)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[Worker-4 3:wor ==\> not found
]{style="font-size:8.0pt;font-family:\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 3 of 5 on 3:wor from
Tale\_Of\_Two\_Cities.txt present=1
[lw]{.SpellE}=worst([len]{.SpellE}=5)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 0 of 5 on 3:wor from
Sense\_And\_Sensibility.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 2 of 5 on 3:wor from
The\_Call\_Of\_The\_Wild.txt present=0
[lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[[msgsnd]{style="font-size:8.0pt;font-family:
\"Courier New\""}]{.SpellE}[ Reply 4 of 5 on 3:wor from Peter\_Pan.txt
present=0 [lw]{.SpellE}=\-\-\--([len]{.SpellE}=4)
[msglen]{.SpellE}=144]{style="font-size:8.0pt;font-family:
\"Courier New\""}

[\*\*prefix(0)
[   ]{style="mso-spacerun:yes"}[ ]{style="mso-spacerun:yes"}received]{style="font-size:8.0pt;font-family:\"Courier New\""}

[Terminating \...]{style="font-size:8.0pt;font-family:\"Courier New\""}

[]{style="mso-bidi-font-weight:bold"}

 

[]{style="mso-bidi-font-weight:bold"}

 

[]{style="mso-bidi-font-weight:bold"}

 

[]{style="mso-bidi-font-weight:bold"}

 

[]{style="mso-bidi-font-weight:bold"}

 

[]{style="mso-bidi-font-weight:bold"}

 

[Search Manager
requirements]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[Must be written in
C]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[Numeric parameter denoting delay will be present and an integer;
if it is zero, then use no
delay]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[At least one prefix will be provided (may not be
valid)]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[Only process prefixes are at least 3 characters should be
processed]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[Only one prefix should be processed at a time.[ 
]{style="mso-spacerun:yes"}Once all the results on a prefix are
returned, the next can be sent to the passage
processor]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-ascii-font-family:Calibri;mso-fareast-font-family:
Calibri;mso-hansi-font-family:Calibri;mso-bidi-font-family:Calibri;mso-bidi-font-weight:
bold"}[Send a prefix message with a zero id to notify the passage
processor to complete]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

 

[Passage processor
requirements]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Written in Java
with the main function in
edu.cs300.PassageProcessor.java]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Read passage
file names from *passages.txt* in root directory (hardcode the
name)]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Read contents of
each passages file in the root
directory]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

 

[]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

 

[General criteria]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Programs will
only be graded on
cs426.ua.edu]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Late submissions
will not be accepted]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Input
criteria:]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Prefixes-at least three characters long and
no longer that 20
characters]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Text Passages-Unlimited number of
passages]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Longest word-Maximum length 100
characters]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Prefix Request -Unlimited number of
requests]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Text Processing-Ignore punctuation, only
store words.[  ]{style="mso-spacerun:yes"}Words with punctuation in them
should be ignored.]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[o[  
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;font-family:\"Courier New\";mso-fareast-font-family:\"Courier New\";
mso-bidi-font-weight:bold"}[Passage Name should be the first 30
characters of the
filename]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[The System V
message queue requires an existing file and integer to create a unique
queue name.[  ]{style="mso-spacerun:yes"}You should create a file using
your crimson id in your home directory. Use [queue\_ids.h]{.SpellE}
header file to create a constant string that holds the path to the queue
and a constant integer to hold the day of your birthday.[ 
]{style="mso-spacerun:yes"}Use CRIMSON\_ID and QUEUE\_NUMBER in the
[ftok]{.SpellE} command to generate the identifier
]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[(see
]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}[[https://github.com/monicadelaine/Spring\_cs300\_project/blob/master/msgsnd\_pr.c]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}](https://github.com/monicadelaine/Spring_cs300_project/blob/master/msgsnd_pr.c)[
for an example)]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[\#define CRIMSON\_ID
\"/home/[anderson]{.SpellE}/[anderson]{.SpellE}\"]{style="font-size:10.0pt;
font-family:\"Courier New\";mso-fareast-font-family:Calibri;mso-fareast-theme-font:
minor-latin;color:black"}

[\#define QUEUE\_NUMBER 12 //day of birth]{style="font-size:10.0pt;
font-family:\"Courier New\";mso-fareast-font-family:Calibri;mso-fareast-theme-font:
minor-latin;color:black"}

[]{style="font-size:10.0pt"}

 

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Place files in
the directory structure below (matches sample
[github]{.SpellE})]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[.]{style="font-size:10.0pt;font-family:Consolas;
mso-fareast-font-family:\"Times New Roman\";color:#242729;border:none windowtext 1.0pt;
mso-border-alt:none windowtext 0in;padding:0in"}[]{style="font-size:
7.5pt;mso-bidi-font-size:10.0pt;font-family:Consolas;mso-fareast-font-family:
\"Times New Roman\";color:#242729;border:none windowtext 1.0pt;mso-border-alt:
none windowtext 0in;padding:0in"}

[├── \_passages.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_Pride\_And\_Prejudice.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_Mansfield\_Park.txt.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_The\_Call\_Of\_The\_Wild.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_Tale\_Of\_Two\_Cities.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_Peter\_Pan.txt]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_edu\_cs300\_MessageJNI.h]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}[
]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;mso-bidi-font-weight:
bold"}[[queue\_ids.h]{style="font-size:7.5pt;mso-bidi-font-size:
10.0pt;font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";
color:#242729;border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;
padding:0in;mso-bidi-font-weight:bold"}]{.SpellE}[]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;font-family:Consolas;
mso-fareast-font-family:\"Times New Roman\";color:#242729;border:none windowtext 1.0pt;
mso-border-alt:none windowtext 0in;padding:0in;mso-bidi-font-weight:bold"}

[├──
\_[longest\_word\_search.h]{.SpellE}]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├──
\_[searchmanager.c]{.SpellE}]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_\<Additional supporting C
files\>.c]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_\<Additional supporting header
files\>.c]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_[edu]{.SpellE}]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}└──
cs300]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
SearchRequest.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
MessageJNI.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
ParallelTextSearch.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
Worker.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
PassageProcessor.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}[       ]{style="mso-tab-count:1"}└──
\<Additional Supporting Java
Source\>.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[├── \_]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}[
]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;font-family:
Menlo;mso-fareast-font-family:Calibri;mso-fareast-theme-font:minor-latin;
color:black"}[[CtCILibrary]{style="font-size:7.5pt;
mso-bidi-font-size:10.0pt;font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";
color:#242729;border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;
padding:0in"}]{.SpellE}[]{style="font-size:7.5pt;mso-bidi-font-size:
10.0pt;font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";
color:#242729;border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;
padding:0in;mso-bidi-font-weight:bold"}

[\|[   ]{style="mso-spacerun:yes"}├──
Trie.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[\|[   ]{style="mso-spacerun:yes"}└──
TrieNode.java]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[└── \_[Makefile]{.SpellE}
]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}*[//if
commands other than those provided are needed to build executables or
dynamic
library]{style="font-size:6.5pt;mso-bidi-font-size:10.0pt;font-family:Consolas;
mso-fareast-font-family:\"Times New Roman\";color:#242729;border:none windowtext 1.0pt;
mso-border-alt:none windowtext 0in;padding:0in"}*[]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;font-family:Consolas;
mso-fareast-font-family:\"Times New Roman\";color:#242729;border:none windowtext 1.0pt;
mso-border-alt:none windowtext 0in;padding:0in"}

[└── \_readme.md]{style="font-size:7.5pt;mso-bidi-font-size:10.0pt;
font-family:Consolas;mso-fareast-font-family:\"Times New Roman\";color:#242729;
border:none windowtext 1.0pt;mso-border-alt:none windowtext 0in;padding:0in"}

[]{style="font-size:10.0pt;font-family:Consolas;
mso-fareast-font-family:\"Times New Roman\";color:#242729"}

 

[]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

 

[Hints:]{style="font-size:10.0pt;mso-bidi-font-weight:bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Use blocking
[msgrcv]{.SpellE}]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Wrap search
manager [msgrcv]{.SpellE} in a while loop since SIGINT will cause the
[msgrcv]{.SpellE} to return with no
message]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

[[·[       ]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:
Ignore"}]{style="font-size:10.0pt;font-family:Symbol;mso-fareast-font-family:Symbol;
mso-bidi-font-family:Symbol;mso-bidi-font-weight:bold"}[Create two
SIGINT handlers: one that gives a starting status that does not include
any shared information and a 2^nd^ handler that returns shared
(protected) information ]{style="font-size:10.0pt;mso-bidi-font-weight:
bold"}

 

 

**Parameters**

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Minimize
resource usage (do not hardcode any values other than given
above)]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Do not
assume any ordering of the message
retrieval]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Maximize
parallel processing ]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Appropriately
protect data structures as
needed]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Minimize
use of global variables (don't use as a mechanism to avoid passing
parameters)]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Synchronize
calls to [msgsnd]{.SpellE} and
[msgrcv]{.SpellE}]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Free any
allocated memory; join any
threads]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Do not
remove IPC queue when done ]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Message
queue key should be your crimson
id]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Programs
should be coded in C language (C99 standard) and will be compiled and
tested on cs426.ua.edu.[  ]{style="mso-spacerun:yes"}If you choose to
program on another system, give yourself enough time verify it works on
cs426.[  ]{style="mso-spacerun:yes"}No other system will be used to test
your code.[  ]{style="mso-spacerun:yes"}May need \_GNU\_SOURCE
switch.]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[You
should use the [pthreads]{.SpellE} library for threading.[ 
]{style="mso-spacerun:yes"}You can use mutexes or condition variables
from the [pthreads]{.SpellE} library and/or semaphores from the
[posix]{.SpellE} library.]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Appropriate
data structures should be selected based on your knowledge of data
structures (CS201,
[etc]{.SpellE}).]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Algorithms
should be efficient and appropriate.[  ]{style="mso-spacerun:yes"}This
program should demonstrate not only your understanding of process
synchronization but your ability to design a program
appropriately]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[No sleeps
other than sleep between sending prefix requests driven by command line
argument]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[       
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.0pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Use
\#ifdef DEBUG to remove/add debug print statements based on compilation
]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}[(]{style="font-size:10.0pt;mso-bidi-font-size:11.0pt"}[-DDEBUG=0
or
-DDEBUG=1)]{style="font-size:10.0pt;mso-bidi-font-size:11.0pt;font-family:Menlo;color:black"}[]{style="font-size:10.0pt;mso-bidi-font-size:11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Use
standard error to print error
messages]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

[[-[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-size:10.5pt;mso-bidi-font-size:11.0pt;font-family:\"Cambria\",serif;
mso-fareast-font-family:Cambria;mso-bidi-font-family:Cambria"}[Use
assert to check for unexpected
conditions]{style="font-size:10.5pt;mso-bidi-font-size:
11.0pt"}

 

**Grading policy**

*[Failure to follow directions will result in point deductions. There
are 70 students in this class.[  ]{style="mso-spacerun:yes"}It is
unreasonable to expect that any exceptions to the procedure will be
made.]{style="mso-bidi-font-size:14.0pt"}*

[]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt"}

 

**[Late assignments will not be
accepted]{style="mso-bidi-font-size:14.0pt"}**[ unless you have a
doctor's note covering the entire period from Feb 28-Mar 23.[ 
]{style="mso-spacerun:yes"}The source code and test results should be
printed and brought to class on Mar 23^rd^.[ 
]{style="mso-spacerun:yes"}Make sure your printout is easy to read (line
wrapping [etc]{.SpellE}).[  ]{style="mso-spacerun:yes"}The source code
should also be turned in via Blackboard (not emailed to me or the TA).[ 
]{style="mso-spacerun:yes"}Test results (using your generated data)
should also be printed and submitted via blackboard in pdf format. Test
result submissions of any other type will not be
graded.]{style="mso-bidi-font-size:14.0pt"}

[]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt"}

 

[This is an individual assignment. 
]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt;
mso-fareast-font-family:\"Times New Roman\";mso-bidi-font-family:\"Times New Roman\""}[The
program must represent your own work.[ 
]{style="mso-spacerun:yes"}]{style="font-size:10.5pt;
mso-bidi-font-size:12.0pt"}[You can discuss high-level concepts. Do not
show your code to anyone.[ 
]{style="mso-spacerun:yes"}]{style="font-size:10.5pt;
mso-bidi-font-size:12.0pt;mso-fareast-font-family:\"Times New Roman\";mso-bidi-font-family:
\"Times New Roman\""}[I reserve the right to ask you about your program
to discern if you indeed wrote the code.[  ]{style="mso-spacerun:yes"}If
you cannot explain your code and choices verbally, you may be turned in
for academic misconduct.
]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt"}[All submissions
will be analyzed to identify possible cases of cheating.  Any cases of
suspected collaboration will be referred to the College of Engineering
Dean.  A zero or low grade is always better than having an academic
misconduct on your academic
record.]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt;mso-fareast-font-family:\"Times New Roman\";
mso-bidi-font-family:\"Times New Roman\""}[]{style="font-size:10.5pt;mso-bidi-font-size:12.0pt"}

 

\*\* Programs will be evaluated based on many functional and design
criteria \*\*

Sample criteria include:

 

70% - functionality

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program contains the correct [trie]{.SpellE} code to produce the
output (find longest words in variety of passages)

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Code for search manager contains correct functionality

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Code for passage processor contains correct functionality

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Hardcoding and lengths as specified

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Signal catch implemented and working

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Process sync correct (threads in PP and signals in SM)

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Maximizes concurrency

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Other functional or correctness features

 

25% - design

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program exhibits defensible design choices in algorithms and
data structures (if you add any)

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program does not contain extra loops or any code that hurts
efficiency

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Other design and efficiency features

 

5% - style

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program must use appropriate and consistent style for naming of
elements

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program must include reasonable whitespace and appropriate
indentation

[[·[      
]{style="font:7.0pt \"Times New Roman\""}]{style="mso-list:Ignore"}]{style="font-family:Symbol;mso-fareast-font-family:Symbol;mso-bidi-font-family:
Symbol"}Program must include comments, especially in areas where you
need to support your choices or where the purpose of the code is
unclear.

 

 

\*\* Clarifications on the assignment will be posted to blackboard.

 
:::
