DESIGN PRINCIPALS
=================








-	For convenience. Not for performance.

	This library is designed to provide better and earlier error check and organization.
	Not for performance. 
	
	Major reason of this library is avoiding mistakes. Objective-C is too much mistake-prone
	language, and overriding a method by mistake is too easy, and there's no warning.
	As a result, managing those feature overriding are very hard.
	
	Also, encapsulation is hard in Objective-C. There's no private method, and all the classes
	are always public. No namespace. It's hard to structure complex program in hierarchical way.
	C++ can provide better way of program structuring.






-	All wrapper classes are just thin wrappers around pointers to Objective-C object pointers.
	Conceptually, a class is something like this;
	
		typedef		NSView*		View;
		
	or something like this;
	
		class
		View
		{
			NSView*			_raw_ptr{nullptr};
		};


	Then, copy is bare pointer copy, not a semantic deep copy. If you want to perform semantic copy,
	then you have to call `copy` method just like an Objective-C object.

	Anyway, unlike Objective-C, copy method is not provided by default. It is a formal convention naming
	semantic copy method as `copy`, so you can call the method just if a class has it.





-	Classes wrapping `CFType` objects are also just a pointer wrapper.
	Conceptually, a `CFType` wrappers are something like this;

		typedef		CGColorRef		Color;


	Or;

		class
		Color
		{
			CGColorRef		_raw_ptr{nullptr};
		};

	`CFType` object wrappers performs automatic reference-counting. (yes, it works exactly like
	Objective-C ARC works!)





-	Type Checks.
	`CFType` based classes are checked by imported CoreFoundation C symbols.
	Objective-C classes are not checked when creating (yet), but will be checked
	when calling any method. This is mainly to avoid importing Objective-C symbols.
	I hope to add type-checks when creating object instances.











Keep it simple by decomposing each features
-------------------------------------------



-	Base classes are not exposed directly by default.
	
	To keep simplicity, all base class functionalities will not be exposed directly.
	Instead, classes may have `as~` series method to provide access to base class features.
	Where appropriate, some base class features may be exposed directly. This is fully case-by-case, 
	and hiding is the default choice.



-	No direct overriding.

	Cocoa uses observer pattern primarily rather then overriding, and
	usually overriding is wrong pattern. In most cases we don't need method overriding.
	Anyway some ancient Cocoa classes are still using method overriding to implement observer
	pattern (yes, that's wrong!), and those classes needs special treatment.

	I am currently using several different approaches to provide method overriding mechanism,
	but none of them are overriding C++ method directly. Every features will be separated into
	a separated observer class. Usually they will become a part of delegate object. I believe
	this is patching a design bugs in old Cocoa classes.

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	