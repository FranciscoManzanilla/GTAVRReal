# _ACTIVITY_FEED_CREATE

--- ns: MISC aliases: ["0x4DCDF92BF64236CD"] --- ## ACTIVITY_FEED_CREATE  // 0x4DCDF92BF64236CD void ACTIVITY_FEED_CREATE(char* captionString, char* condensedCaptionString);  Creates and opens a new activity feed post to start filling in.  **Note**: This is a PS4 related native, resulting in a nullsub on the PC platform. This native won't do anything when invoked.  ## Parameters * **captionString**: The main text or caption for the activity feed post. This is the primary message displayed in the feed entry. * **condensedCaptionString**: A shorter or condensed version of the caption, used in cases where space is limited or a brief summary is required.

### Parameters
* const char* p0
* const char* p1

### Return Value
* void

### Notes
* Build: 323
* Does nothing (it's a nullsub). Seems to be PS4 specific.

