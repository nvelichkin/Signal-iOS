//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

import Foundation

/**
 * We synchronize access to state in this class using this queue.
 */
public func assertOnQueue(_ queue: DispatchQueue) {
    if #available(iOS 10.0, *) {
        dispatchPrecondition(condition: .onQueue(queue))
    } else {
        // Skipping check on <iOS10, since syntax is different and it's just a development convenience.
    }
}

// Once we're on Swift4.2 we can mark this as inlineable
// @inlinable
public func AssertIsOnMainThread(file: String = #file,
                                 function: String = #function,
                                 line: Int = #line) {
    guard Thread.isMainThread else {
        let filename = (file as NSString).lastPathComponent
        owsFail("\(filename):\(line) in \(function): Must be on main thread.")
        return
    }
}

// Once we're on Swift4.2 we can mark this as inlineable
// @inlinable
public func owsFail(_ logMessage: String,
                    file: String = #file,
                    function: String = #function,
                    line: Int = #line) {
    // TODO: Format using owsFormatLogMessage() once it is merged.
    let message = "\(file) \(function) \(line): \(logMessage)"
    Logger.error(message)
    Logger.flush()
    assertionFailure(message)
}

// Once we're on Swift4.2 we can mark this as inlineable
// @inlinable
public func owsProdExit(_ logMessage: String,
                        file: String = #file,
                        function: String = #function,
                        line: Int = #line) {

    owsFail(logMessage, file: file, function: function, line: line)
    fatalError(logMessage)
}
